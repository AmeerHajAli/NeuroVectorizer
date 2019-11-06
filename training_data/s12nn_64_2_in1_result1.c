#include "header.h"

short in1[64];
short in2[64];
short in3[64];
int   result1[64] ALIGNED16;
int   result2[64] ALIGNED16;
int   result3[64] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in1, short *__restrict__ in2, short *__restrict__ in3, int* __restrict__ result1, int* __restrict__ result2, int* __restrict__ result3) {
  int i;
  for (i = 0; i < 64; i+=2) {
    result1[i] = (int) in1[i];
    result2[i] = (int) in2[i];
    result3[i] = (int) in3[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result1[0], &result1[64]);
  init_memory(&result2[0], &result2[64]);
  init_memory(&result3[0], &result3[64]);
  init_memory(&in1[0], &in1[64]);
  init_memory(&in2[0], &in2[64]);
  init_memory(&in3[0], &in3[64]);
  BENCH("Example10b", example10b(in1,in2,in3,result1,result2,result3), Mi*4/64*512, digest_memory(&result1[0], &result1[64])+digest_memory(&result2[0], &result2[64])+digest_memory(&result3[0], &result3[64]));
 
  return 0;
}