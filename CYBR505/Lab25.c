#include <stdio.h>

int Fib(int n);

int main()
{
	int n, result;

	printf("Please enter n:\n");
	scanf_s("%d", &n);
	result = Fib(n);
	printf("The nth fibonacci number is:\t%d", result);
	getchar();
	getchar();

	return 0;

}

int Fib(int n)
{
	int r = 0;
	int y = 1;
	if (n == 0)
		return r;
	else if (n == 1)
		return y;
	else {
		r = Fib(n-1)+Fib(n-2);
		return r;
	}
}