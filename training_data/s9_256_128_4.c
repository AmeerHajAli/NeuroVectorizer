#include "header.h"

int assign[256][128];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<256; i++) {
     for (j=0; j<128; j++) {
       assign[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&assign[0][0], &assign[0][128]);
  BENCH("Example8",   example8(8), 32768, digest_memory(&assign[0][0], &assign[0][128]));
 
  return 0;
}
