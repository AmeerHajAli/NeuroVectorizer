#include "header.h"

int Out[128][8192];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128; i++) {
     for (j=0; j<8192; j++) {
       Out[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Out[0][0], &Out[0][8192]);
  BENCH("Example8",   example8(8), 1024, digest_memory(&Out[0][0], &Out[0][8192]));
 
  return 0;
}
