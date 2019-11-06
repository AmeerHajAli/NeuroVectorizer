#include "header.h"

short short_a[2048];
short short_b[2048];
short short_c[2048];
int   out1[2048] ALIGNED16;
int   out2[2048] ALIGNED16;
int   out3[2048] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ short_a, short *__restrict__ short_b, short *__restrict__ short_c, int* __restrict__ out1, int* __restrict__ out2, int* __restrict__ out3) {
  int i;
  for (i = 0; i < 2048; i++) {
    out1[i] = (int) short_a[i];
    out2[i] = (int) short_b[i];
    out3[i] = (int) short_c[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out1[0], &out1[2048]);
  init_memory(&out2[0], &out2[2048]);
  init_memory(&out3[0], &out3[2048]);
  init_memory(&short_a[0], &short_a[2048]);
  init_memory(&short_b[0], &short_b[2048]);
  init_memory(&short_c[0], &short_c[2048]);
  BENCH("Example10b", example10b(short_a,short_b,short_c,out1,out2,out3), Mi*4/2048*512, digest_memory(&out1[0], &out1[2048])+digest_memory(&out2[0], &out2[2048])+digest_memory(&out3[0], &out3[2048]));
 
  return 0;
}
