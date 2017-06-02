#include <stdio.h>

int main()
{
	int n;
	double f, c;

	printf("DEGREES\t\tDEGREES\n");
	printf("CELSIUS\t\tFAHRENHEIT\n");
	printf("--------\t---------\n");

	for (n=1;n<11;n=n++)
	{
		c = 5 * (double)n;
		f = (9.0/5.0) * c + 32;
		printf("%.0lf\t\t%.2lf\n", c, f);
	}

	getchar();
	getchar();
	return 0;
}