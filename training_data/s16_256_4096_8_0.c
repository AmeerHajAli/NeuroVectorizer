#include "header.h"

int   ia[8];
int G[256][4096];
int G2[256+8][4096];

__attribute__((noinline))
void example14(int in[][4096], int coeff[][4096], int *out) {
  int k,j,i=0;
  for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 256; i++)
        for (j = 0; j < 4096; j++)
          sum += in[i+k][j] * coeff[i][j];

    out[k] = sum;
  }
}

int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[8]);
  init_memory(&G[0][0], &G[0][4096]);
  init_memory(&G2[0][0],&G2[0][4096]);
  BENCH("Example14",  example14(G2,G,ia), 256, digest_memory(&ia[0], &ia[8]));
  return 0;
}