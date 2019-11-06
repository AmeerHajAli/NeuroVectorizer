#include "header.h"

int result[2048] ALIGNED16;
int in1[2048] ALIGNED16;
int in2[2048] ALIGNED16;

__attribute__((noinline))
void example4b () {
   int i;

   /* feature: support for read accesses with a compile time known misalignment  */
   for (i=0; i<2048-4; i+=2){
      result[i] = in1[i+1] -in2[i+3];
      result[i+1]=in1[i] -in2[i+2];
   }
}

int main(int argc,char* argv[]){
  init_memory(&result[0], &result[2048]);
  init_memory(&in1[0], &in1[2048]);
  init_memory(&in2[0], &in2[2048]);
 
  BENCH("Example4b",  example4b(), Mi*2/2048*512, digest_memory(&result[0], &result[2048]));
  
  return 0;
}
