#include "header.h"

short in[128];
int   result[128] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in, int* __restrict__ result) {
  int i;
  for (i = 0; i < 128; i+=2) {
    result[i] = (int) in[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result[0], &result[128]);
  init_memory(&in[0], &in[128]);
  BENCH("Example10b", example10b(in,result), Mi*4/128*512, digest_memory(&result[0], &result[128]));
 
  return 0;
}
