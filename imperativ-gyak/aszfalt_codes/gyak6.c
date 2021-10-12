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
	Product prods[3] = {{Small, 12.5f},
											{Medium, 4.5f},
											{Small, 6.5f}};
	Product *prod = find(3, prods, Small);
	printf("Size: %d, price: %f\n", prod->size, prod->price);

	return 0;
}

Product *find(int const length, Product const *const product, enum Size searchFor)
{
	int minI = 0;
	for (int i = 0; i < length; i++)
	{
		if (product[i].size == searchFor && product[minI].price > product[i].price)
		{
			minI = i;
		}
	}

	return &product[minI];
}
