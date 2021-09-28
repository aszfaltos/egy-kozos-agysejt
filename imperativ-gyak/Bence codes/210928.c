#include <stdio.h>

int fibonacci(int n){
  if(n<0){
    return (-1);
  }
  if (n==1) {
    return 1;
  }
  if(n==0){
    return 0;
  }
  return fibonacci(n-1)+fibonacci(n-2);
}

int main(int argc, char const *argv[]) {
  int num;
  printf("%s\n", "irj be egy szamot" );
  scanf("%d", &num );
  printf("%d\n", fibonacci(num) );

  return 0;
}
