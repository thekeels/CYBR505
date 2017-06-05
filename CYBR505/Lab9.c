#include<stdio.h>

int Lab9()
{
	int i, j;
	double score_sum, score, average;
	
	for (i = 1; i < 21; i++)
	{
		score_sum = 0;
		printf("Enter student %d grade\n", i);
		for (j = 0; j < 4; j++)
		{

			scanf_s("%lf", &score);
			score_sum += score;
		}
		average = score_sum / 4;
		printf("The average grade for student %i is %.4g\n", i, average);
	}
	getchar();
	getchar();
	return 0;
}