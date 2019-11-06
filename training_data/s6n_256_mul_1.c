#include "header.h"

int out[256] ALIGNED16;
int in1[256] ALIGNED16;
int in2[256] ALIGNED16;

__attribute__((noinline))
void example4b () {
   int i;

   /* feature: support for read accesses with a compile time known misalignment  */
   for (i=0; i<256-4; i+=2){
      out[i] = in1[i+1] *in2[i+3];
      out[i+1]=in1[i] *in2[i+2];
   }
}

int main(int argc,char* argv[]){
  init_memory(&out[0], &out[256]);
  init_memory(&in1[0], &in1[256]);
  init_memory(&in2[0], &in2[256]);
 
  BENCH("Example4b",  example4b(), Mi*2/256*512, digest_memory(&out[0], &out[256]));
  
  return 0;
}
