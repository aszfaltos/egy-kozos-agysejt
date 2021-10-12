#include <stdio.h>

enum Size{
  Small, Medium, Large
};

typedef struct{
  enum Size size;
  float price;
}Product;

Product const * const find(
  int const length,
  Product const * const prods,
  enum Size const searchFor
){
  int minI = 0;
  while (minI< length && prods[minI].size != searchFor) {
    minI++;
  }
  if (minI==length) {
    return 0;
  }

  for (size_t i = minI+1; i < length; i++) {
    if (prods[i].size == searchFor && prods[minI].price > prods[i].price) {
      minI = i;
    }
  }
  return &prods[minI];
}

int main(int argc, char const *argv[]) {
  Product prods[3] = {{Small, 12.5f},
											{Medium, 4.5f},
											{Small, 6.5f}};
	Product const * const prod = find(3, prods, Small);
	printf("Size: %d, price: %f\n", prod->size, prod->price);
  return 0;
}
