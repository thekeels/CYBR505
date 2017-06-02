#include <stdio.h>
int main(void)
{
	int labnumber;
	int endlabs = 1;
	int Lab1(), Lab2(), Lab3(), Lab4(), Lab5(), Lab6(), Lab7();
	do {
		system("cls");
		printf("Enter the lab number you want to run (0 to exit): ");
		scanf_s("%d", &labnumber);
		printf("\n\n******************************************************************************\n\n");
		switch(labnumber)
		{
		case 1:
			Lab1();
		
		case 2:
			Lab2();
		case 3:
			Lab3();
		case 4:
			Lab4();
		case 5:
			Lab5();
		case 6:
			Lab6();
		case 7:
			Lab7();
		default:
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