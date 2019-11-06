#include "header.h"

int output[512] ALIGNED16;
int input1[512] ALIGNED16;
int input2[512] ALIGNED16;

__attribute__((noinline))
void example4b () {
   int i;

   /* feature: support for read accesses with a compile time known misalignment  */
   for (i=0; i<512-4; i++){
      output[i] = input1[i+1] -input2[i+3];
   }
}

int main(int argc,char* argv[]){
  init_memory(&output[0], &output[512]);
  init_memory(&input1[0], &input1[512]);
  init_memory(&input2[0], &input2[512]);
 
  BENCH("Example4b",  example4b(), Mi*2/512*512, digest_memory(&output[0], &output[512]));
  
  return 0;
}
