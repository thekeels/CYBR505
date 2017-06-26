#include <stdio.h>

void Create(int ArrayVar[11], int);
void Reverse(int ArrayVar[11], int n);
void PrintArray(int ArrayVar[11], int n);

int main()
{
	int n;		
	int ArrayVal[11];  // Set up an array
	printf("Enter a value for array size n: ");
	scanf_s("%d", &n); // Get size of array from user
	while (n < 2 || n>11) // If size of array is outside range, ask for valid input
	{
		printf("\nOutside range, enter a number between 2 and 11: ");
		scanf_s("%d", &n);
	}
	Create(ArrayVal,n); // Gets values for the array
	printf("This is the array prior to reversing:\n");
	PrintArray(ArrayVal, n); // Prints the array
	Reverse(ArrayVal,n); // Reverses values in the array
	printf("This is the array after reversing:\n");
	PrintArray(ArrayVal,n); // Prints after the reversal
	getchar();
	getchar();
	return 0;
}
// Function -- Create -- creates an array of size n, of values divisible by 3
// Input: Array memory address, size of desired array
// Output: Array of size n, of values > 0 and divisible by 3
void Create(int ArrayVar[11], int n)
{
	int i = 0;
	printf("Enter the values for the array. They must be positive and divisible by 3: ");
	while (i < n) // Keep reading values until you reach the size as entered by the user
	{ 
		printf("\nEnter element %d: ", i);
		scanf_s("%d", &ArrayVar[i]);
		while (ArrayVar[i] < 0 || (ArrayVar[i] % 3 != 0)) // Entered values must be positive and divisible by 3
		{
			printf("Invalid input, must be positive and divisible by 3, try again\n");
			printf("Enter element %d: ", i);
			scanf_s("%d", &ArrayVar[i]);
		}
		i++;
	}

	return;
}
// Function -- Reverse -- reverses the values in the array
// Input: Array memory address, size of array
// Output: Reversed array
void Reverse(int ArrayVar[11], int n)
{
	int swap[11]; // Create a temporary swap array
	int j = 0;
	for (int i = n-1; i >= 0; i--)
	{ 
		swap[j] = ArrayVar[i]; // Store values in reverse order into the swap array
		j++;
	}
	for (int i = 0; i < n; i++) 
	{
		ArrayVar[i] = swap[i]; // Replace the values in ArrayVar with the values in swap
	}
	return;
}
// Function -- PrintArray -- prints the array
// Input: memory address of the array, size of array
// Output: prints the array
void PrintArray(int ArrayVar[11], int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", ArrayVar[i]);
	}
	return;
}