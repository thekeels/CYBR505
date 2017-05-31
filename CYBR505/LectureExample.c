/*
* Performs three square root computations
*/

#include<stdio.h>  /* definitions of printf, scanf */
#include<math.h>   /* definition of sqrt */

int main()
{
	double first, second,   /*input - two data values */
		first_sqrt,			/*output - square root of first */
		second_sqrt,		/*output - square root of second*/
		sum_sqrt;			/*output - square root of sum*/
	/* Get first number and display its square root. */
	printf("Enter the first number> ");
	scanf_s("%lf", &first);
	first_sqrt = sqrt(first);
	/* Get second number and display its square root. */
	printf("The square root of the first number is %.2f\n", first_sqrt);
	printf("Enter the second number> ");
	scanf_s("%lf", &second);
	second_sqrt = sqrt(second);
	/* Display the square root of the sum of the two numbers. */
	printf("THe square root of the second number is %.2f\n", second_sqrt);

	sum_sqrt = sqrt(first + second);
	printf("The square root of the sum of the two numbers is %.2f\n", sum_sqrt);
	getchar();
	getchar();
	return (0);
}