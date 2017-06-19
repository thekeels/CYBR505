#include <stdio.h>

int Fact(int n);

int Lab14()
{
	int n, output;
	int sentinel = -1000;

	printf("Please enter n\n");
	scanf_s("%d", &n);
	while (sentinel == -1000) {
		if (n >= 0 && n <= 10) {
			output = Fact(n);
			sentinel = 0;
		}
		else
		{
			printf("This number is outside the range.\n");
			printf("Please enter n\n");
			scanf_s("%d", &n);
		}
	}
	
	printf("%d! is %d", n, output);
	getchar();
	getchar();
	return(0);
}
// Fact caclulates the factorial of a number i.e. n(!) = 1*2*3*4...*(n-1)*n
// Input: integer to calculate factorial of
// Output: integer result
int Fact(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}