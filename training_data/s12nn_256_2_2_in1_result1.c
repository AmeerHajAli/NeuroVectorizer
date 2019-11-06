#include "header.h"

short in1[256];
short in2[256];
short in3[256];
int   result1[256] ALIGNED16;
int   result2[256] ALIGNED16;
int   result3[256] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in1, short *__restrict__ in2, short *__restrict__ in3, int* __restrict__ result1, int* __restrict__ result2, int* __restrict__ result3) {
  int i;
  for (i = 0; i < 256-1; i+=2) {
    result1[i] = (int) in1[i];
result1[i+1] = (int) in1[i+1];
    result2[i] = (int) in2[i];
result2[i+1] = (int) in2[i+1];
    result3[i] = (int) in3[i];
result3[i+1] = (int) in3[i+1];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result1[0], &result1[256]);
  init_memory(&result2[0], &result2[256]);
  init_memory(&result3[0], &result3[256]);
  init_memory(&in1[0], &in1[256]);
  init_memory(&in2[0], &in2[256]);
  init_memory(&in3[0], &in3[256]);
  BENCH("Example10b", example10b(in1,in2,in3,result1,result2,result3), Mi*4/256*512, digest_memory(&result1[0], &result1[256])+digest_memory(&result2[0], &result2[256])+digest_memory(&result3[0], &result3[256]));
 
  return 0;
}