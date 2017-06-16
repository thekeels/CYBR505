#include <stdio.h>

int main()
{
	int i, index, max;
	int A[5];
	// Fill List1 array with values
	printf("Please enter values to List1 array\n");
	for (i = 0;i<5;i++)
	{
		scanf_s("%d", A+i);
	}
	max = A[0];
	// Find the max of the values entered
	for (i = 0; i < 5; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
			index = i;
		}
		else {}
	}
	// Print the array index and value of the largest element
	printf("The index of largest element in List1 array is %d\n", index);
	printf("The largest element in List1 array is %d", max);
	getchar();
	getchar();
	return 0;
}