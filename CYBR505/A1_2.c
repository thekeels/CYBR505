#include <stdio.h>

void Create(int ArrayVar[11], int);
void Reverse(int ArrayVar[11], int n);
void PrintArray(int ArrayVar[11], int n);

int main()
{
	int n;
	int ArrayVal[11];
	printf("Enter a value for array size n: ");
	scanf_s("%d", &n);
	while (n < 2 || n>11)
	{
		printf("\nOutside range, enter a number between 2 and 11: ");
		scanf_s("%d", &n);
	}
	Create(ArrayVal,n);
	printf("This is the array prior to reversing:\n");
	PrintArray(ArrayVal, n);
	Reverse(ArrayVal,n);
	printf("This is the array after reversing:\n");
	PrintArray(ArrayVal,n);
	getchar();
	getchar();
	return 0;
}

void Create(int ArrayVar[11], int n)
{
	int i = 0;
	printf("Enter the values for the array. They must be positive and divisible by 3: ");
	while (i < n)
	{ 
		printf("\nEnter element %d: ", i);
		scanf_s("%d", &ArrayVar[i]);
		while (ArrayVar[i] < 0 || (ArrayVar[i] % 3 != 0))
		{
			printf("Invalid input, must be positive and divisible by 3, try again\n");
			printf("Enter element %d: ", i);
			scanf_s("%d", &ArrayVar[i]);
		}
		i++;
	}

	return;
}

void Reverse(int ArrayVar[11], int n)
{
	int swap[11];
	int j = 0;
	for (int i = n-1; i >= 0; i--)
	{
		swap[j] = ArrayVar[i];
		j++;
	}
	for (int i = 0; i < n; i++)
	{
		ArrayVar[i] = swap[i];
	}
	return;
}

void PrintArray(int ArrayVar[11], int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", ArrayVar[i]);
	}
	return;
}