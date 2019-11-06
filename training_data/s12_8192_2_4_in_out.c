#include "header.h"

short in[8192];
int   out[8192] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in, int* __restrict__ out) {
  int i;
  for (i = 0; i < 8192-3; i+=4) {
    out[i] = (int) in[i];
out[i+1] = (int) in[i+1];
out[i+2] = (int) in[i+2];
out[i+3] = (int) in[i+3];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out[0], &out[8192]);
  init_memory(&in[0], &in[8192]);
  BENCH("Example10b", example10b(in,out), Mi*4/8192*512, digest_memory(&out[0], &out[8192]));
 
  return 0;
}
