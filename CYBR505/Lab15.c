#include<stdio.h>
int main()
{
	int n, i;
	int num;
	int A[9];
	// Create an array with up to 9 elements
	printf("Enter a value between 2-9 for the array size n\n");
	scanf_s("%d", &n);
	// Validity check for the array size
	while (n < 2 || n>9)
	{
		printf("The array size, n, is not valid. Try again\n");
		scanf_s("%d", &n);
	}
	// Fill the array with values
	printf("Please enter %d numbers: \n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &num);
		A[i] = num;
	}
	// Print the values of the array that were entered
	printf("\nThe elements of the array are:\n");
	for (i = 0; i < n; i++)
	{
		printf("The element %d of array is %d\n", i,A[i]);
	}
	// Print the values of the array that were entered, in reverse order
	printf("\nThe elements of the array in reverse order are:\n");
	for (i = n-1; i >= 0; i--)
	{
		printf("The element %d of array is %d\n", i, A[i]);
	}

	getchar();
	getchar();
	return 0;
}