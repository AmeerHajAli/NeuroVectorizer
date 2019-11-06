#include "header.h"

short in1[4096];
short in2[4096];
int   assign1[4096] ALIGNED16;
int   assign2[4096] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in1, short *__restrict__ in2, int* __restrict__ assign1, int* __restrict__ assign2) {
  int i;
  for (i = 0; i < 4096; i++) {
    assign1[i] = (int) in1[i];
    assign2[i] = (int) in2[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&assign1[0], &assign1[4096]);
  init_memory(&assign2[0], &assign2[4096]);
  init_memory(&in1[0], &in1[4096]);
  init_memory(&in2[0], &in2[4096]);
  BENCH("Example10b", example10b(in1,in2,assign1,assign2), Mi*4/4096*512, digest_memory(&assign1[0], &assign1[4096])+digest_memory(&assign2[0], &assign2[4096]));
 
  return 0;
}
