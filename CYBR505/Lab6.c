#include<stdio.h>

int Lab6(void)
{
	int x;
	printf("Please enter a number: \n");
	scanf_s("%d", &x);
	if (x % 2 == 0)
	{
		printf("This number is even.\n");
	}
	else
	{
		printf("This number is odd.\n");
	}
	getchar();
	getchar();
	return 0;

}