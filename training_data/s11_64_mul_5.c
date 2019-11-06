#include "header.h"

short mul2[64];
short s2[64];
short s3[64];
int   mul1[64] ALIGNED16;
int   i2[64] ALIGNED16;
int   i3[64] ALIGNED16;

__attribute__((noinline))
void example10a(short *__restrict__ mul2, short *__restrict__ s2, short *__restrict__ s3, int* __restrict__ mul1, int* __restrict__ i2, int* __restrict__ i3) {
  int i;
  for (i = 0; i < 64; i++) {
    mul1[i] = i2[i] + i3[i];
    mul2[i] = s2[i] + s3[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&mul1[0], &mul1[64]);
  init_memory(&i2[0], &i2[64]);
  init_memory(&i3[0], &i3[64]);
  init_memory(&mul2[0], &mul2[64]);
  init_memory(&s2[0], &s2[64]);
  init_memory(&s3[0], &s3[64]);
  BENCH("Example10a", example10a(mul2,s2,s3,mul1,i2,i3), Mi/64*512, digest_memory(&mul1[0], &mul1[64]) + digest_memory(&mul2[0], &mul2[64]));
 
  return 0;
}
