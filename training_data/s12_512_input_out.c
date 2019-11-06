#include "header.h"

short input[512];
int   out[512] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ input, int* __restrict__ out) {
  int i;
  for (i = 0; i < 512; i++) {
    out[i] = (int) input[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out[0], &out[512]);
  init_memory(&input[0], &input[512]);
  BENCH("Example10b", example10b(input,out), Mi*4/512*512, digest_memory(&out[0], &out[512]));
 
  return 0;
}
