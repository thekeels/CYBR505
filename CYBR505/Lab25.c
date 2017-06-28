#include <stdio.h>

void printFib(int n, int x);
int Fib(int n);

int Lab25()
{
	int n, x;

	printf("Please enter n:\n");
	scanf_s("%d", &n);
	/*printf("The fibonacci sequence is: \n");
	for (int i = 0; i <= n; i++)
	{
		result = Fib(i);
		printf("%d\n", result);
	}*/
	x = n;
	printFib(n, x);
	//printf("\nThe nth fibonacci number is:\t%d", result);
	
	getchar();
	getchar();
	return 0;

}
// Fibonacci formula - to calculate nth fibonnaci number, added fib(n-1) + fib(n-2)
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

void printFib(int n, int x)
{
	if (n == -1)
		return;
	else
	{
		printf("%d\t", Fib(x-n));
		printFib(n - 1, x);
		return;
	}
	
	return;

}