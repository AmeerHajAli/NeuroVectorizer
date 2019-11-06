#include "header.h"

int a[1024] ALIGNED16;
int b[1024] ALIGNED16;

__attribute__((noinline))
void example4c (){
   int i;
    const int MAX = 4;
   /* feature: support for if-conversion  */
   for (i=0; i<1024; i++){
      int j = a[i];
      b[i] = (j > MAX ? MAX : 0);
   }
}

int main(int argc,char* argv[]){
  init_memory(&a[0], &a[1024]);
  init_memory(&b[0], &b[1024]);
  BENCH("Example4c",  example4c(), Mi*4/1024*512, digest_memory(&b[0], &b[1024]));
 
  
  return 0;
}
