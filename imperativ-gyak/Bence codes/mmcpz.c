#include <stdio.h>
#include <stdlib.h>
void mmcpy(void * dest, void * src, int size){
  char * d = (char * const)dest;
  char const *s = (char const * const)src;
  while (size-- > 0) {
    *(d++) = *(s++);
  }
  //for (int i = 0; i < size; i++) {
  //  *d = *s;}
}

void swapvoid(void * a, void * b, int size, void * tmp){
  mmcpy(tmp, a, size);
  mmcpy(a, b, size);
  mmcpy(b, tmp, size);
}

void swapvoid2(void *a, void *b, int size){
  void * tmp = malloc(size);
  swapvoid(a,b,size,tmp);
  free(tmp);
}

int * alloc(unsigned size){
  int * arr = (int *)malloc(size*sizeof(int));
  for (size_t i = 0; i < size; i++) {
    arr[i] = i;
  }
  return arr;
}

void swappointer(void ** a, void ** b){
  void ** tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, char const *argv[]) {
  int a;
  int b =3;
  mmcpy(&a, &b, sizeof(int));
  int * meow = alloc(10);
  printf("%d\n",meow[2] );
  free(meow);
  a = 2;
  b = 4;
  
  printf("%d\n",a );

  return 0;
}
