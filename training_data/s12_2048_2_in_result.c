#include "header.h"

short in[2048];
int   result[2048] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in, int* __restrict__ result) {
  int i;
  for (i = 0; i < 2048; i+=2) {
    result[i] = (int) in[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result[0], &result[2048]);
  init_memory(&in[0], &in[2048]);
  BENCH("Example10b", example10b(in,result), Mi*4/2048*512, digest_memory(&result[0], &result[2048]));
 
  return 0;
}
