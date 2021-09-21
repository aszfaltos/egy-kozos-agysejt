#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int getMin(int size, int inp[size]);
int getMax(int size, int inp[size]);
int getSum(int size, int inp[size]);
struct arrayData getArrayData(int size, int inp[size]);
struct arrayData
{
	int min;
	int max;
	int sum;
};

int main()
{
	// 10 element
	{
		printf("Ten element array:\n");
		int arr[10] = {2, 3, 4, 5, 6, 7, 8, 2, 6, 3};
		printf("min: %d\n", getMin(10, arr));
		printf("max: %d\n", getMax(10, arr));
		printf("sum: %d\n", getSum(10, arr));
		printf("\n");
		struct arrayData arrDat = getArrayData(10, arr);
		printf("min: %d, max: %d, sum: %d\n", arrDat.min, arrDat.max, arrDat.sum);
	}
	printf("------------------------------------------------\n");
	// 8 element
	{
		printf("Eight element array:\n");
		int arr[8] = {2, 3, 4, 5, 6, 7, 8, 2};
		printf("min: %d\n", getMin(8, arr));
		printf("max: %d\n", getMax(8, arr));
		printf("sum: %d\n", getSum(8, arr));
		printf("\n");
		struct arrayData arrDat = getArrayData(8, arr);
		printf("min: %d, max: %d, sum: %d\n", arrDat.min, arrDat.max, arrDat.sum);
	}
	printf("------------------------------------------------\n");
	// user input
	{
		printf("User input:\n");
		// input size
		int size = 0;
		char input[30];
		do
		{
			printf("Enter the length of the array (1-10): ");
			scanf("%s", input);
			if (isdigit(input[0]))
			{
				size = atoi(input);
				if (size <= 10 && size >= 1)
				{
					break;
				}
			}
		} while (1);
		// input array elements
		int arr[10];
		for (int i = 0; i < size; ++i)
		{
			do
			{
				printf("Enter number #%d: ", i + 1);
				scanf("%s", input);
				if (isdigit(input[0]) || (input[0] == '-' && isdigit(input[1])))
				{
					arr[i] = atoi(input);
					break;
				}
			} while (1);
		}
		struct arrayData arrDat = getArrayData(size, arr);
		printf("min: %d, max: %d, sum: %d\n", arrDat.min, arrDat.max, arrDat.sum);
	}
	return 0;
}

struct arrayData getArrayData(int size, int inp[size])
{
	struct arrayData ret = {inp[0], inp[0], inp[0]};
	for (int i = 1; i < size; ++i)
	{
		if (inp[i] > ret.max)
		{
			ret.max = inp[i];
		}
		if (inp[i] < ret.min)
		{
			ret.min = inp[i];
		}
		ret.sum += inp[i];
	}
	return ret;
}

int getMin(int size, int inp[size])
{
	int min = inp[0];
	for (int i = 1; i < size; ++i)
	{
		if (inp[i] < min)
		{
			min = inp[i];
		}
	}
	return min;
}

int getMax(int size, int inp[size])
{
	int max = inp[0];
	for (int i = 1; i < size; ++i)
	{
		if (inp[i] > max)
		{
			max = inp[i];
		}
	}
	return max;
}

int getSum(int size, int inp[size])
{
	int sum = inp[0];
	for (int i = 1; i < size; ++i)
	{
		sum += inp[i];
	}
	return sum;
}
