#include "header.h"

int input[512] ALIGNED16;
int result[512] ALIGNED16;

__attribute__((noinline))
void example4c (){
   int i;
    const int MAX = 4;
   /* feature: support for if-conversion  */
   for (i=0; i<512-1; i+=2){
      int j = input[i];
      result[i] = (j > MAX ? MAX : 0);
      result[i+1] = j;
   }
}

int main(int argc,char* argv[]){
  init_memory(&input[0], &input[512]);
  init_memory(&result[0], &result[512]);
  BENCH("Example4c",  example4c(), Mi*4/512*512, digest_memory(&result[0], &result[512]));
 
  
  return 0;
}
