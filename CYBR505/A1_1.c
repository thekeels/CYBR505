#include <stdio.h>

void split(int Array[20], int positive[20], int negative[20]);
void printArrays(int positive[20], int negative[20]);

int main() {

	int Array[20] = { 1,2,3,4,5,6,7,8,9,10,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
	int positive[20], negative[20];
	split(Array, positive, negative);
	printArrays(positive, negative);
	getchar();
	getchar();
	return;
}


void split(int Array[20], int positive[20], int negative[20])
{
	for (int i = 0; i < 20; i++)
	{
		if (Array[i] >= 0)
		{
			positive[i] = Array[i];
		}
		else
		{
			negative[i] = Array[i];
		}
	}
}

void printArrays(int positive[20], int negative[20])
{

	printf("Positive Array\t\tNegative Array\n");
	for (int i = 0; i < 20; i++)
	{
		printf("%d\t\t\t%d\n", positive[i], negative[i]);
	}
	
}