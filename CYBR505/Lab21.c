#include <stdio.h>


int Lab21()
{

	int i, j;
	int ArrayVar[5][4];
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 4; j++)
		{
			ArrayVar[i][j] = 0;
		}
	}

	printf("Please enter numbers to fill up the array\n\n");
	int sum = 0;
	

	for (i = 0; i < 5; i++)
	{
		sum = 0;
		for (j = 0; j < 4; j++)
		{
			scanf_s("%d", &ArrayVar[i][j]);
			//printf("%d\t", ArrayVar[i][j]);
			sum += ArrayVar[i][j];
		}

		printf("\t%d\n", sum);
	}
	printf("\n");
	for (j = 0; j < 4; j++)
	{
		sum = 0;
		for (i = 0; i < 5; i++)
		{
			sum += ArrayVar[i][j];
		}
		printf("%d\t", sum);
	}
	getchar();
	getchar();
	return 0;
}