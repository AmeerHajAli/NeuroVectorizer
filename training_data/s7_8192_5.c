#include "header.h"

int i1[8192] ALIGNED16;
int o[8192] ALIGNED16;

__attribute__((noinline))
void example4c (){
   int i;
    const int MAX = 4;
   /* feature: support for if-conversion  */
   for (i=0; i<8192; i++){
      int j = i1[i];
      o[i] = (j > MAX ? MAX : 0);
   }
}

int main(int argc,char* argv[]){
  init_memory(&i1[0], &i1[8192]);
  init_memory(&o[0], &o[8192]);
  BENCH("Example4c",  example4c(), Mi*4/8192*512, digest_memory(&o[0], &o[8192]));
 
  
  return 0;
}
