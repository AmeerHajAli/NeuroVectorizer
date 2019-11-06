
#include "header.h"
int out[1024] ALIGNED16;
__attribute__((noinline))
void example2a (int x) {
   int i;

   /* feature: support for unknown loop bound  */
   /* feature: support for loop invariants  */
   for (i=0; i< 1024-1 ; i+=2) {
      out[i] = x;
out[i+1] = -x;
   }
}
int main(int argc,char* argv[]){
 
  init_memory(&out[0], &out[1024]);
  BENCH("Example2a",  example2a(2), Mi*4/1024*512, digest_memory(&out[0], &out[1024]));
  
  return 0;
}
