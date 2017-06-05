#include <stdio.h>

int main()
{
	int i, j;

	for (i = 9; i >0; i--)
	{
		for (j = 9; j > i; j--)
		{
			printf("_");
		}
		for (j = 0; j < i; j++)
		{
			printf("%d", i);
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}