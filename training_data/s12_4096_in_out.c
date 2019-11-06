#include "header.h"

short in[4096];
int   out[4096] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in, int* __restrict__ out) {
  int i;
  for (i = 0; i < 4096; i++) {
    out[i] = (int) in[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out[0], &out[4096]);
  init_memory(&in[0], &in[4096]);
  BENCH("Example10b", example10b(in,out), Mi*4/4096*512, digest_memory(&out[0], &out[4096]));
 
  return 0;
}
