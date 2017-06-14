#include <stdio.h>

float AverageTwo(int num1, int num2);

int main()
{
	int score1, score2;
	float ave;
	printf("Please enter the 2 numbers to average: ");
	scanf_s("%d%d", &score1, &score2);
	ave = AverageTwo(score1, score2);
	printf("\nThe average is: %.2f", ave);
	getchar();
	getchar();
	return 0;
}
// AverageTwo is a function to take 2 integers and compute the float average.
// Inputs: 2 integers
// Outputs: 1 float
float AverageTwo(int num1, int num2)
{
	float average = (num1 + num2) / 2;
	return average;
}