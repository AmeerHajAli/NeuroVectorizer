#include "header.h"

int assign[8192][64];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<8192-1; i+=2) {
     for (j=0; j<64-1; j+=2) {
       assign[i][j] = x;
       assign[i+1][j] = x;
       assign[i][j+1] = x;
       assign[i+1][j+1] = x;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&assign[0][0], &assign[0][64]);
  BENCH("Example8",   example8(8), 2048, digest_memory(&assign[0][0], &assign[0][64]));
 
  return 0;
}
