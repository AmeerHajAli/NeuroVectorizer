#include "header.h"

int sum[1024] ALIGNED16;
int in1[1024] ALIGNED16;
int in2[1024] ALIGNED16;

__attribute__((noinline))
void example4b () {
   int i;

   /* feature: support for read accesses with a compile time known misalignment  */
   for (i=0; i<1024-4; i+=2){
      sum[i] = in1[i+1] -in2[i+3];
      sum[i+1]=in1[i] -in2[i+2];
   }
}

int main(int argc,char* argv[]){
  init_memory(&sum[0], &sum[1024]);
  init_memory(&in1[0], &in1[1024]);
  init_memory(&in2[0], &in2[1024]);
 
  BENCH("Example4b",  example4b(), Mi*2/1024*512, digest_memory(&sum[0], &sum[1024]));
  
  return 0;
}
