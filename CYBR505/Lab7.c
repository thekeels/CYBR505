#include<stdio.h>

int main(void)
{
	int sum, elements, i, number;
	sum = 0;
	printf("Enter the number of elements you would like to check for divisibility by 3: \n");
	scanf_s("%d", &elements);
	printf("Please enter the numbers:\n");
	while (elements <3 || elements > 100)
	{
		printf("The number is not acceptable enter another one.\n");
		scanf_s("%d", &elements);
	}
	printf("Please enter the numbers:\n");
	for (i = 0; i < elements; i++)
	{
		scanf_s("%d", &number);
		
			if (number % 3 == 0)
			{
				printf("The number is divisible by 3.\n");
				sum += number;
			}
			
		
	}

	printf("Sum of the numbers that are divisible by 3 is: %d\n", sum);
	getchar();
	getchar();
	return 0;

}