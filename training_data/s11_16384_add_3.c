#include "header.h"

short short1[16384];
short short2[16384];
short short3[16384];
int   int1[16384] ALIGNED16;
int   int2[16384] ALIGNED16;
int   int3[16384] ALIGNED16;

__attribute__((noinline))
void example10a(short *__restrict__ short1, short *__restrict__ short2, short *__restrict__ short3, int* __restrict__ int1, int* __restrict__ int2, int* __restrict__ int3) {
  int i;
  for (i = 0; i < 16384; i++) {
    int1[i] = int2[i] + int3[i];
    short1[i] = short2[i] + short3[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&int1[0], &int1[16384]);
  init_memory(&int2[0], &int2[16384]);
  init_memory(&int3[0], &int3[16384]);
  init_memory(&short1[0], &short1[16384]);
  init_memory(&short2[0], &short2[16384]);
  init_memory(&short3[0], &short3[16384]);
  BENCH("Example10a", example10a(short1,short2,short3,int1,int2,int3), Mi/16384*512, digest_memory(&int1[0], &int1[16384]) + digest_memory(&short1[0], &short1[16384]));
 
  return 0;
}
