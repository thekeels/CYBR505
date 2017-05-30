#include <stdio.h>
int main(void)
{
	int labnumber;
	int endlabs = 1;
	int Lab1(), Lab2(), Lab3();
	do {
		system("cls");
		printf("Enter the lab number you want to run (0 to exit): ");
		scanf_s("%d", &labnumber);
		printf("\n\n******************************************************************************\n\n");
		if (labnumber == 1)
		{
			Lab1();
		}
		else if (labnumber == 2)
		{
			Lab2();
		}
		else if (labnumber == 3)
		{
			Lab3();
		}
		else
		{
			endlabs = 0;
		}
		printf("\n\n******************************************************************************\n\n");
		printf("\n\nContinue? (0 = no, 1 = yes) ");
		scanf_s("%d", &endlabs);
	}
	while (endlabs == 1);
	getchar();
	return 0;
}