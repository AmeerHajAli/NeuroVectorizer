#include "header.h"

int result[8192] ALIGNED16;
int in1[8192] ALIGNED16;
int in2[8192] ALIGNED16;

__attribute__((noinline))
void example4b () {
   int i;

   /* feature: support for read accesses with a compile time known misalignment  */
   for (i=0; i<8192-4; i+=2){
      result[i] = in1[i+1] *in2[i+3];
      result[i+1]=in1[i] *in2[i+2];
   }
}

int main(int argc,char* argv[]){
  init_memory(&result[0], &result[8192]);
  init_memory(&in1[0], &in1[8192]);
  init_memory(&in2[0], &in2[8192]);
 
  BENCH("Example4b",  example4b(), Mi*2/8192*512, digest_memory(&result[0], &result[8192]));
  
  return 0;
}
