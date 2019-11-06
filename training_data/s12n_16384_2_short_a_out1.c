#include "header.h"

short short_a[16384];
short short_b[16384];
int   out1[16384] ALIGNED16;
int   out2[16384] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ short_a, short *__restrict__ short_b, int* __restrict__ out1, int* __restrict__ out2) {
  int i;
  for (i = 0; i < 16384; i+=2) {
    out1[i] = (int) short_a[i];
    out2[i] = (int) short_b[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out1[0], &out1[16384]);
  init_memory(&out2[0], &out2[16384]);
  init_memory(&short_a[0], &short_a[16384]);
  init_memory(&short_b[0], &short_b[16384]);
  BENCH("Example10b", example10b(short_a,short_b,out1,out2), Mi*4/16384*512, digest_memory(&out1[0], &out1[16384])+digest_memory(&out2[0], &out2[16384]));
 
  return 0;
}
