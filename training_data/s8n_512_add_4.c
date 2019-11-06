#include "header.h"

int res[512] ALIGNED16;
int in[512] ALIGNED16;

__attribute__((noinline))
void  example7 (int x) {
   int i;

   /* feature: support for read accesses with an unknown misalignment  */
   for (i=0; i<512-x; i++){
      res[i] += in[i+x];
   }
}

int main(int argc,char* argv[]){
  init_memory(&res[0], &res[512]);
  init_memory(&in[0], &in[512]);
 
  BENCH("Example7",   example7(4), Mi*8/512*512, digest_memory(&res[0], &res[512]));
  return 0;
}