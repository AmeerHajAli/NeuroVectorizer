#include "header.h"

short short_a[1024];
short short_b[1024];
short short_c[1024];
int   out1[1024] ALIGNED16;
int   out2[1024] ALIGNED16;
int   out3[1024] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ short_a, short *__restrict__ short_b, short *__restrict__ short_c, int* __restrict__ out1, int* __restrict__ out2, int* __restrict__ out3) {
  int i;
  for (i = 0; i < 1024; i+=2) {
    out1[i] = (int) short_a[i];
    out2[i] = (int) short_b[i];
    out3[i] = (int) short_c[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out1[0], &out1[1024]);
  init_memory(&out2[0], &out2[1024]);
  init_memory(&out3[0], &out3[1024]);
  init_memory(&short_a[0], &short_a[1024]);
  init_memory(&short_b[0], &short_b[1024]);
  init_memory(&short_c[0], &short_c[1024]);
  BENCH("Example10b", example10b(short_a,short_b,short_c,out1,out2,out3), Mi*4/1024*512, digest_memory(&out1[0], &out1[1024])+digest_memory(&out2[0], &out2[1024])+digest_memory(&out3[0], &out3[1024]));
 
  return 0;
}
