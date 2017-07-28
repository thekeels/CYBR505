#include <stdio.h>

void FillArray(int array_size, int Array[10]);
void PrintArray(int array_size, int Array[10]);
void SortArray(int array_size, int Array[10]);

int main()
{
	int Array[10];
	int array_size;
	printf("Enter the size of the array: ");
	scanf_s("%d", &array_size);

	while (array_size < 2 || array_size>10)
	{
		printf("\nError, array size out of range, please enter between 2 and 10: ");
		scanf_s("%d", &array_size);
	}
	FillArray(array_size, Array);
	PrintArray(array_size, Array);
	SortArray(array_size, Array);
	PrintArray(array_size, Array);
	return 0;
}
 
void FillArray(int array_size, int Array[10])
{
	for (int i = 0; i < array_size; i++)
	{
		printf("\nEnter element %d: ", i);
		scanf_s("%d", Array+i);
	}
	return;
}

void PrintArray(int array_size, int Array[10])
{
	printf("\nArray: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n\n");
	return;
}

void SortArray(int array_size, int Array[10])
{
	int temp = 0;
	printf("Sorted Array: ");
	for (int i = 0;i < array_size; i++)
	{
		for (int j = i + 1; j < array_size; j++)
		{
			if (Array[j] < Array[i])
			{
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;

			}
		}
	}
	return;
}