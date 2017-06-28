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
	int recurse;
	int firstnum = 0;
	int secondnum = 1;
	if (n == 0)
		return firstnum;
	else if (n == 1)
		return secondnum;
	else {
		recurse = Fib(n-1)+Fib(n-2);
		return recurse;
	}
}