#include <stdio.h>

float converter(float celsius)
{
	float fahrenheit = (9.0 / 5.0) * celsius + 32;
	return fahrenheit;
}
int main()
{
	int n;
	float f, c;

	printf("DEGREES\t\tDEGREES\n");
	printf("CELSIUS\t\tFAHRENHEIT\n");
	printf("--------\t---------\n");

	for (n=1;n<11;n=n++)
	{
		c = 5 * n;
		f = converter(c);
		printf("%.0f\t\t%.2f\n", c, f);
	}

	getchar();
	getchar();
	return 0;
}