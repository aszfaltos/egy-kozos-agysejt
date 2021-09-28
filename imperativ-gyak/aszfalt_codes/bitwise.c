#include <stdio.h>

int bitwiseAdd(int a, int b);

int bitwiseMultiply(int a, int b);

int main()
{
	printf("%d\n", bitwiseMultiply(10, 200));
	return 0;
}

int bitwiseAdd(int a, int b)
{
	int leftovers = (a & b) << 1;
	int sum = a ^ b;
	while (leftovers != 0)
	{
		int tmp = sum;
		sum ^= leftovers;
		leftovers = (tmp & leftovers) << 1;
	}

	return sum;
}

int bitwiseMultiply(int a, int b)
{
	int tmp[31];
	// ossze szorozza a szamjegyeket
	for (int i = 30; i >= 0; i = bitwiseAdd(i, -1))
	{
		tmp[i] = 0;
		if ((b >> i) & 1)
		{
			tmp[i] = a << i;
		}
	}

	// osszeadja a szorzatokat
	int sum = 0;
	for (int i = 0; i < 31; i = bitwiseAdd(i, 1))
	{
		sum = bitwiseAdd(sum, tmp[i]);
	}
	return sum;
}
