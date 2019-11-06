#include "header.h"

int Output[128][2048];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128; i++) {
     for (j=0; j<2048; j++) {
       Output[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Output[0][0], &Output[0][2048]);
  BENCH("Example8",   example8(8), 4096, digest_memory(&Output[0][0], &Output[0][2048]));
 
  return 0;
}
