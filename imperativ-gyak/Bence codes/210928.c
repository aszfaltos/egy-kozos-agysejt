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

float series(int n){
  if (n<0) {
    return -1;
  }
  if (n==0) {
    /* code */
    return 0;
  }
  if (n==1) {
    /* code */
    return 1;
  }
  if (n==2) {
    /* code */
    return 4;
  }
  return (series(n-1)*0.5)+(series(n-2)*series(n-2))-series(n-3);
}

struct Person{
  int age;
  int height;
  int id;
};

int avgHeight(int size,struct Person people[]){
  int sum =0;
  for (size_t i = 0; i < size; i++) {
    sum += people[i].height;
  }
  return sum/size;
}

int main(int argc, char const *argv[]) {
  struct Person people[5];

  /*int num;
  printf("%s\n", "irj be egy szamot" );
  scanf("%d", &num );*/
  //printf("%d\n", fibonacci(num));
  //printf("%f\n", series(num));

  for (size_t i = 0; i < 5; i++) {
    printf("%d%s\n", i+1, ". ember eletkora: " );
    scanf("%d", &people[i].age );
    printf("%d%s\n", i+1, ". ember magassaga: " );
    scanf("%d", &people[i].height );
    printf("%d%s\n", i+1, ". ember id-ja: " );
    scanf("%d", &people[i].id );
  }

  printf("%s%d\n", "Az atlag magassag: ", avgHeight(5, people) );

  return 0;
}
