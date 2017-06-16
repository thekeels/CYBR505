#include<stdio.h>

float convert(int);
int main()
{
	int c;
	float f;
	printf("Please input a temperature in Celsius (integer) to convert to Fahrenheit\n=> ");
	scanf_s("%d", &c);
	f = convert(c);
	printf("\nThe temperature in Fahrenheit is:\n=> %.8lf\n", f);
	getchar();
	getchar();
	return(0);
}

float convert(int celsius)
{
	float fahrenheit = (9.0 / 5.0) * celsius + 32;
	return fahrenheit;
}