#include<stdio.h>

void arraysort(int *, int n);


int main()
{
	int i;
	int array[10];
	int num_elements;
	printf("Enter the number of elements for the array (up to 10): ");
	scanf_s("%d", &num_elements);
	while (num_elements < 1 || num_elements >10)
	{
		printf("\nThis number is out of range, try again.\n");
		scanf_s("%d", &num_elements);
	}
	printf("\nEnter the elements for the array:");
	for (i = 0; i < num_elements; i++)
	{
		scanf_s("%d", array+i);
	}
	arraysort(array,num_elements);
	for (i = 0; i < num_elements; i++)
	{
		printf("\nElement %d = %d\n", i, array[i]);
	}

	getchar();
	getchar();
	return 0;

}

void arraysort(int* inputarray, int n)
{
	int i, j;
	int swap;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (inputarray[i] >= inputarray[i + 1])
			{
				swap = inputarray[i + 1];
				inputarray[i + 1] = inputarray[i];
				inputarray[i] = swap;
			}
			else {}

		}
	}
	return;
}
