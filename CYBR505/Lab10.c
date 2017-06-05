#include <stdio.h>

int Lab10()
{
	int i, j;

	for (i = 1; i < 6; i++)
	{
		for (j = 5; j>i; j--)
		{
			printf(".");
		}
		for (j = 1; j <= i; j++)
		{
			printf("%d", i);
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;

}