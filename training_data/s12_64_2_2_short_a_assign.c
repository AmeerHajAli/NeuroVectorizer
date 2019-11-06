#include "header.h"

short short_a[64];
int   assign[64] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ short_a, int* __restrict__ assign) {
  int i;
  for (i = 0; i < 64-1; i+=2) {
    assign[i] = (int) short_a[i];
assign[i+1] = (int) short_a[i+1];
  }
}
int main(int argc,char* argv[]){
  init_memory(&assign[0], &assign[64]);
  init_memory(&short_a[0], &short_a[64]);
  BENCH("Example10b", example10b(short_a,assign), Mi*4/64*512, digest_memory(&assign[0], &assign[64]));
 
  return 0;
}
