#include "header.h"

int Output[1024][2048];
__attribute__((noinline))
void example8 (int y) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<1024-1; i+=2) {
     for (j=0; j<2048-1; j+=2) {
       Output[i][j] = y;
       Output[i+1][j] = y;
       Output[i][j+1] = y;
       Output[i+1][j+1] = y;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Output[0][0], &Output[0][2048]);
  BENCH("Example8",   example8(8), 512, digest_memory(&Output[0][0], &Output[0][2048]));
 
  return 0;
}
