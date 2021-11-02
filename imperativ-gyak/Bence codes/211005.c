#include <stdio.h>
void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
int main(int argc, char const *argv[]) {
/*  int a = 42;
  int * p = &a;
  printf("%ld\n", *p );
  *p = 123;
  printf("%ld\n", a);
  int arr[5] = {1,2,3,4,5};

  p = arr +1;
  ++p;
  printf("arr = %ld, p = %ld\n", arr , p );
  printf("%ld\n", *p);
  p = &arr[1];
  printf("%ld\n", *p);
*/
  int a = 2;
  int b = 4;
  swap(&a,&b);
  printf(" a = %ld b = %ld \n",a, b );


  return 0;
}
