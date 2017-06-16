#include <stdio.h>

int main()
{
	int i, index, max;
	int A[5];
	printf("Please enter values to List1 array\n");
	for (i = 0;i<5;i++)
	{
		scanf_s("%d", A+i);
	}
	max = A[0];
	for (i = 0; i < 5; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
			index = i;
		}
		else {}
	}
	printf("The index of largest element in List1 array is %d\n", index);
	printf("The largest element in List1 array is %d", max);
	getchar();
	getchar();
	return 0;
}