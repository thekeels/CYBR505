#include <stdio.h>
int main(void)
{
	float R1, R2, R3, Rtotal;
	printf("Enter the value for resistor R1: ");
	scanf_s("%f", &R1);
	printf("\nEnter the value for resistor R2: ");
	scanf_s("%f", &R2);
	printf("\nEnter the value for resistor R3: ");
	scanf_s("%f", &R3);
	Rtotal = 1 / ((1 / R1) + (1 / R2) + (1 / R3));
	printf("\n\nThe combined resistance for three resistors of values %.0f, %.0f, %.0f, is: %.5f", R1, R2, R3, Rtotal);
	getchar();
	getchar();
	return (0);
}