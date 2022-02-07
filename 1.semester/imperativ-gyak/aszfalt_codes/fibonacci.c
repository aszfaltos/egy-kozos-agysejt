#include <stdio.h>

void fibonacciRec(int n1, int n2, int n, int index);

void fibonacciFor(int n);

void notFibonacciRec(int n1, int n2, int n3, int n, int index);

int main()
{
	fibonacciRec(0, 1, 10, 0);
	fibonacciFor(10);
	notFibonacciRec(0, 1, 4, 11, 0);
	return 0;
}

void fibonacciRec(int n1, int n2, int n, int index)
{
	if (index == 0)
	{
		printf("%d %d", n1, n2);
	}
	if (index >= n - 2)
	{
		printf("\n_________________________________");
		printf("\n%d\n", n2);
		return;
	}
	printf(" %d", n1 + n2);
	fibonacciRec(n2, n1 + n2, n, ++index);
}

void fibonacciFor(int n)
{
	int a = 0;
	int b = 1;
	printf("%d %d", a, b);
	for (int i = 0; i < n; i++)
	{
		int c = a;
		a = b;
		b += c;
		printf(" %d", b);
	}
	printf("\n_________________________________");
	printf("\n%d\n", b);
}

void notFibonacciRec(int n1, int n2, int n3, int n, int index)
{
	if (index == 0)
	{
		printf("%d %d %d", n1, n2, n3);
	}
	if (index >= n - 3)
	{
		printf("\n_________________________________");
		printf("\n%d\n", n3);
		return;
	}
	int next = n3 / 2 + n2 * n2 - n1;
	printf(" %d", next);
	notFibonacciRec(n2, n3, next, n, ++index);
}