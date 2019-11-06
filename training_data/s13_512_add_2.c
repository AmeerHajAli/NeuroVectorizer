#include "header.h"

int output1[512] ALIGNED16;
int input1[512] ALIGNED16;
int input2[512] ALIGNED16;
int output2[512] ALIGNED16;

__attribute__((noinline))
void example11() {
   int i;
  for (i = 0; i < 512/4; i++){
    output1[i] = input1[2*i+1] * input2[2*i+1] - input1[2*i] * input2[2*i];
    output2[i] = input1[2*i] * input2[2*i+1] +input1[2*i+1] * input2[2*i];
  }
}

int main(int argc,char* argv[]){
  init_memory(&output1[0], &output1[512]);
  init_memory(&input1[0], &input1[512]);
  init_memory(&input2[0], &input2[512]);
  init_memory(&output2[0], &output2[512]);
  BENCH("Example11",  example11(), Mi*4/512*256, digest_memory(&output2[0], &output2[512]));
 
  return 0;
}
