#include "header.h"

int res[2048] ALIGNED16;
int in[2048] ALIGNED16;

__attribute__((noinline))
void  example7 (int x) {
   int i;

   /* feature: support for read accesses with an unknown misalignment  */
   for (i=0; i<2048-x; i++){
      res[i] += in[i+x];
   }
}

int main(int argc,char* argv[]){
  init_memory(&res[0], &res[2048]);
  init_memory(&in[0], &in[2048]);
 
  BENCH("Example7",   example7(4), Mi*8/2048*512, digest_memory(&res[0], &res[2048]));
  return 0;
}
