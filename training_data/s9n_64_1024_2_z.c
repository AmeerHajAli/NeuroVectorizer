#include "header.h"

int Output[64][1024];
__attribute__((noinline))
void example8 (int z) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<64-1; i+=2) {
     for (j=0; j<1024-1; j+=2) {
       Output[i][j] = z;
       Output[i+1][j] = z;
       Output[i][j+1] = z;
       Output[i+1][j+1] = z;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Output[0][0], &Output[0][1024]);
  BENCH("Example8",   example8(8), 16384, digest_memory(&Output[0][0], &Output[0][1024]));
 
  return 0;
}
