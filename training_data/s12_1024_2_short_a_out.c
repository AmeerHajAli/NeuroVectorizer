#include "header.h"

short short_a[1024];
int   out[1024] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ short_a, int* __restrict__ out) {
  int i;
  for (i = 0; i < 1024; i+=2) {
    out[i] = (int) short_a[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out[0], &out[1024]);
  init_memory(&short_a[0], &short_a[1024]);
  BENCH("Example10b", example10b(short_a,out), Mi*4/1024*512, digest_memory(&out[0], &out[1024]));
 
  return 0;
}
