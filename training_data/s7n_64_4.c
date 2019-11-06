#include "header.h"

int in[64] ALIGNED16;
int res[64] ALIGNED16;

__attribute__((noinline))
void example4c (){
   int i;
    const int MAX = 4;
   /* feature: support for if-conversion  */
   for (i=0; i<64-1; i+=2){
      int j = in[i];
      res[i] = (j > MAX ? MAX : 0);
      res[i+1] = j;
   }
}

int main(int argc,char* argv[]){
  init_memory(&in[0], &in[64]);
  init_memory(&res[0], &res[64]);
  BENCH("Example4c",  example4c(), Mi*4/64*512, digest_memory(&res[0], &res[64]));
 
  
  return 0;
}
