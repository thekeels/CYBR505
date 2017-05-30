#include <stdio.h>
#include <math.h>
int main(void)
{
	double a, b, c, root1, root2;
	double imag;
	printf("Enter the coefficients: \n");
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);
	scanf_s("%lf", &c);
	root1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	root2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
	printf("The two roots of the function, ax^2 +bx +c =0, are:\n");
	if ((pow(b, 2) - 4 * a*c)<0) {
		printf("...Sorry, this quadratic equation has complex roots!\n");
	}
	else {
		printf("x1= %lf\n", root1);
		printf("x1= %lf\n", root2);
	}

	getchar();
	getchar();
	return 0;
}