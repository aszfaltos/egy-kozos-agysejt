#include <stdio.h>

int powi(int value, unsigned const expo);

int main()
{
	int number = 0;
	printf("asd: ");
	scanf("%d", &number);

	int i = 0;
	int maxi = 0;

	while (number / powi(10, i) > 0)
	{
		maxi = i;
		++i;
	}

	i = 0;
	while ((number / powi(10, maxi)) % 10 == (number % powi(10, (i + 1))) / powi(10, i))
	{
		--maxi;
		++i;
		if (maxi - i <= 1)
		{
			printf("palindrom\n");
			break;
		}
	}

	if (maxi - i > 1)
	{
		printf("nem palindrom\n");
	}

	return 0;
}

int powi(int value, unsigned const expo)
{
	int ret = 1;
	for (unsigned i = 0; i < expo; ++i)
	{
		ret *= value;
	}
	return ret;
}