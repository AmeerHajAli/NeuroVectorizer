#include "header.h"

int assign[2048][8192];
__attribute__((noinline))
void example8 (int z) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<2048-1; i+=2) {
     for (j=0; j<8192-1; j+=2) {
       assign[i][j] = z;
       assign[i+1][j] = z;
       assign[i][j+1] = z;
       assign[i+1][j+1] = z;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&assign[0][0], &assign[0][8192]);
  BENCH("Example8",   example8(8), 64, digest_memory(&assign[0][0], &assign[0][8192]));
 
  return 0;
}
