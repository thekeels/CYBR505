#include<stdio.h>

float convert(int);
int main()
{
	int c;
	float f;
	printf("Please input a temperature in Celsius (integer) to convert to Fahrenheit\n=> ");
	scanf_s("%d", &c);
	// Convert celsius value to fahrenheit
	f = convert(c);
	// Print the fahrenheit value
	printf("\nThe temperature in Fahrenheit is:\n=> %.8lf\n", f);
	getchar();
	getchar();
	return(0);
}
/***************************************/
//convert --- converts an integer celsius value into a float fahrenheit value
// Input: integer celsius value
// Output: float fahrenheit value
/***************************************/
float convert(int celsius)
{
	float fahrenheit = (9.0 / 5.0) * celsius + 32;
	return fahrenheit;
}