#include "header.h"

int result[8192][64];
__attribute__((noinline))
void example8 (int y) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<8192-1; i+=2) {
     for (j=0; j<64-1; j+=2) {
       result[i][j] = y;
       result[i+1][j] = y;
       result[i][j+1] = y;
       result[i+1][j+1] = y;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&result[0][0], &result[0][64]);
  BENCH("Example8",   example8(8), 2048, digest_memory(&result[0][0], &result[0][64]));
 
  return 0;
}
