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

Product const *find(int const length, Product const *const product, enum Size const searchFor);

int main()
{
	Product prods[3] = {{Medium, 12.5f},
											{Small, 4.5f},
											{Small, 6.5f}};
	Product *prod = find(3, prods, Small);
	printf("Size: %d, price: %f\n", prod->size, prod->price);

	return 0;
}

Product const *find(int const length, Product const *const product, enum Size const searchFor)
{
	int minI = -1;
	for (int i = 0; i < length; i++)
	{
		if (product[i].size == searchFor)
		{
			if (minI < 0)
			{
				minI = i;
			}
			if (minI >= 0 && product[minI].price > product[i].price)
			{
				minI = i;
			}
		}
	}

	return &product[minI];
}
