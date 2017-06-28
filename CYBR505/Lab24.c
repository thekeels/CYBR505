#include <stdio.h>

int Factorial(int n);

int Lab24()
{
	int n, result;
	printf("Please enter n:\n");
	scanf_s("%d", &n);
	result = Factorial(n);
	printf("\nThe nth factorian number is:\t%d", result);
	getchar();
	getchar();
	return 0;
}

int Factorial(int n)
{
	int r = 1;
	if (n == 0)
		return r;
	else
	{
		r = Factorial(n-1);
		return n * r;
	}
}