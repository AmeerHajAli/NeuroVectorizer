#include "header.h"

int result[128][256];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128; i++) {
     for (j=0; j<256; j++) {
       result[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&result[0][0], &result[0][256]);
  BENCH("Example8",   example8(8), 32768, digest_memory(&result[0][0], &result[0][256]));
 
  return 0;
}
