#include<stdio.h>

int Lab6(void)
{
	int x, odd_sum, even_sum, max_num;
	odd_sum = even_sum = 0;
	printf("How many numbers do you want to add up?\n");
	scanf_s("%d", &max_num);
	for (int count = 0; count < max_num; count++)
	{
		printf("Enter a number: ");
		scanf_s("%d", &x);
		if (x % 2 == 0)
		{
			printf("(%d is even)\n", x);
			even_sum = even_sum + x;

		}
		else
		{
			printf("(%d is odd)\n", x);
			odd_sum = odd_sum + x;
		}
	}
	printf("The sum of all even numbers is %d. The sum of all odd numbers is %d.\n", even_sum, odd_sum);
	getchar();
	getchar();
	return 0;

}