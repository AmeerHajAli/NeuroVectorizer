#include "header.h"

unsigned int in1[2048];
unsigned int in2[2048];

__attribute__((noinline))
void example9 (unsigned *ret) {
  int i;

  /* feature: support summation reduction.
     note: in case of floats use -funsafe-math-optimizations  */
  unsigned int difference = 0;
  for (i = 0; i < 2048; i++) {
    difference += (in1[i] +in2[i]);
  }

  *ret = difference;
}

int main(int argc,char* argv[]){
  unsigned dummy = 0;
  init_memory(&in1[0], &in1[2048]);
  init_memory(&in2[0], &in2[2048]);
  BENCH("Example9",   example9(&dummy), Mi*4/2048*512, dummy);
 
  return 0;
}
