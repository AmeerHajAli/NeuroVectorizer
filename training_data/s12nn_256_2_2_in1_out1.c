#include "header.h"

short in1[256];
short in2[256];
short in3[256];
int   out1[256] ALIGNED16;
int   out2[256] ALIGNED16;
int   out3[256] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in1, short *__restrict__ in2, short *__restrict__ in3, int* __restrict__ out1, int* __restrict__ out2, int* __restrict__ out3) {
  int i;
  for (i = 0; i < 256-1; i+=2) {
    out1[i] = (int) in1[i];
out1[i+1] = (int) in1[i+1];
    out2[i] = (int) in2[i];
out2[i+1] = (int) in2[i+1];
    out3[i] = (int) in3[i];
out3[i+1] = (int) in3[i+1];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out1[0], &out1[256]);
  init_memory(&out2[0], &out2[256]);
  init_memory(&out3[0], &out3[256]);
  init_memory(&in1[0], &in1[256]);
  init_memory(&in2[0], &in2[256]);
  init_memory(&in3[0], &in3[256]);
  BENCH("Example10b", example10b(in1,in2,in3,out1,out2,out3), Mi*4/256*512, digest_memory(&out1[0], &out1[256])+digest_memory(&out2[0], &out2[256])+digest_memory(&out3[0], &out3[256]));
 
  return 0;
}
