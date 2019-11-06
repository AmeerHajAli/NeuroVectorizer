#include "header.h"

short input[2048];
int   out[2048] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ input, int* __restrict__ out) {
  int i;
  for (i = 0; i < 2048; i++) {
    out[i] = (int) input[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out[0], &out[2048]);
  init_memory(&input[0], &input[2048]);
  BENCH("Example10b", example10b(input,out), Mi*4/2048*512, digest_memory(&out[0], &out[2048]));
 
  return 0;
}