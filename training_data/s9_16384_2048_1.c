#include "header.h"

int Out[16384][2048];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<16384; i++) {
     for (j=0; j<2048; j++) {
       Out[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Out[0][0], &Out[0][2048]);
  BENCH("Example8",   example8(8), 32, digest_memory(&Out[0][0], &Out[0][2048]));
 
  return 0;
}
