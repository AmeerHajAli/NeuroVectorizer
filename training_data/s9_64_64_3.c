#include "header.h"

int result[64][64];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<64; i++) {
     for (j=0; j<64; j++) {
       result[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&result[0][0], &result[0][64]);
  BENCH("Example8",   example8(8), 262144, digest_memory(&result[0][0], &result[0][64]));
 
  return 0;
}
