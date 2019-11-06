#include "header.h"

int G[128][128];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128; i++) {
     for (j=0; j<128; j++) {
       G[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&G[0][0], &G[0][128]);
  BENCH("Example8",   example8(8), 65536, digest_memory(&G[0][0], &G[0][128]));
 
  return 0;
}
