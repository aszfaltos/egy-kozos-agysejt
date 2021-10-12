#include <stdio.h>

enum Size
{
	Small,
	Medium,
	Large
};

typedef struct
{
	enum Size size;
	float price;
} Product;

Product *find(int const length, Product const *const product, enum Size searchFor);

int main()
{
	Product prods[3] = {{Small, 0.5f},
											{Medium, 4.5f},
											{Large, 6.5f}};
	Product *prod = find(3, prods, Medium);
	printf("Size: %d, price: %f\n", prod->size, prod->price);

	return 0;
}

Product *find(int const length, Product const *const product, enum Size searchFor)
{
	int i = 0;
	while (i < length && product[i].size != searchFor)
	{
		++i;
	}

	return &product[i];
}
