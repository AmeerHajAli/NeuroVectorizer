#include "header.h"

short short_a[256];
int   assign[256] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ short_a, int* __restrict__ assign) {
  int i;
  for (i = 0; i < 256-3; i+=4) {
    assign[i] = (int) short_a[i];
assign[i+1] = (int) short_a[i+1];
assign[i+2] = (int) short_a[i+2];
assign[i+3] = (int) short_a[i+3];
  }
}
int main(int argc,char* argv[]){
  init_memory(&assign[0], &assign[256]);
  init_memory(&short_a[0], &short_a[256]);
  BENCH("Example10b", example10b(short_a,assign), Mi*4/256*512, digest_memory(&assign[0], &assign[256]));
 
  return 0;
}
