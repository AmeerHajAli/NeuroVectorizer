#include "header.h"

int G[128][2048];
__attribute__((noinline))
void example8 (int y) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128-1; i+=2) {
     for (j=0; j<2048-1; j+=2) {
       G[i][j] = y;
       G[i+1][j] = y;
       G[i][j+1] = y;
       G[i+1][j+1] = y;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&G[0][0], &G[0][2048]);
  BENCH("Example8",   example8(8), 4096, digest_memory(&G[0][0], &G[0][2048]));
 
  return 0;
}
