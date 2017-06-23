#include <stdio.h>

int main()
{
	int i, j;
	int Array1[3][3] = { { 1,1,1 },{ 2,2,2 },{ 3,3,3 } };
	int Array2[3][3] = { { 1,1,1 },{ 2,2,2 },{ 3,3,3 } }; 
	int Array3[3][3];


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Array3[i][j] = Array2[i][j] + Array1[i][j];
		}
	}
	getchar();
	getchar();
	return 0;
}