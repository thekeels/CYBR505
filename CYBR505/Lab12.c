#include<stdio.h>
int Lab12()
{
	int i, num;
	int max_value = -32768;
	printf("Enter 5 numbers, I will display the maximum value of the numbers entered: ");
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &num);
		if(num>max_value)
		{
			max_value = num;
		}
		else;
	}
	printf("The maximum value of the five numbers entered is: %d", max_value);
	getchar();
	getchar();
	return 0;
}