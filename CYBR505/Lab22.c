#include <stdio.h>

int Lab22()
{
	int i, j;
	int ArrayVar[4][4];

	printf("Input the numbers into array\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf_s("%d", &ArrayVar[i][j]);
		}
	}
	
	printf("The numbers in the diagonal of array are:\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", ArrayVar[i][i]);
	}
	
	getchar();
	getchar();
	return 0;

}