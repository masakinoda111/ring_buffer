#include <stdio.h>
#include <unistd.h>

const int buffer_length = 8;
int buffer[buffer_length];
int latest = buffer_length - 1 ;

//xをバッファに入れる関数
void rbPut(int x){
  if(latest == buffer_length - 1){
    latest = 0;
  }
  else{
    latest += 1;
  }
  buffer[latest] = x;
}

//n個前の値を参照する関数
int rbGet(int n){
  int tmp;
  if(latest >= n){
    tmp = latest - n;
  }
  else{
    tmp = latest - n + buffer_length;
  }
  return (buffer[tmp]);
}

//sample code
int main(void){
  int i = 0;
  while(1){
    rbPut(i);
    int x = rbGet(0);
    int y = rbGet(1);
    int z = rbGet(2);
    printf("i = %d, x = %d, y = %d, z = %d\n", i, x, y, z);
    i += 1;
    sleep(1);
  }
  return (0);
}
