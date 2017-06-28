#include <stdio.h>
#include <stdlib.h>
#include "LabList.h"

int main(void)
{
	int labnumber;
	int endlabs = 1;

	do {
		system("cls");
		printf("Enter the lab number you want to run (0 to exit): ");
		scanf_s("%d", &labnumber);
		printf("\n\n******************************************************************************\n\n");
		switch(labnumber)
		{
		case 1:
			Lab1();
			break;
		case 2:
			Lab2();
			break;
		case 3:
			Lab3();
			break;
		case 4:
			Lab4();
			break;
		case 5:
			Lab5();
			break;
		case 6:
			Lab6();
			break;
		case 7:
			Lab7();
			break;
		case 8:
			Lab8();
			break;
		case 9:
			Lab9();
			break;
		case 10:
			Lab10();
			break;
		case 11:
			Lab11();
			break;
		case 12:
			Lab12();
			break;
		case 13:
			Lab13();
			break;
		case 14:
			Lab14();
			break;
		case 15:
			Lab15();
			break;
		case 16:
			Lab16();
			break;
		case 17:
			Lab17();
			break;
		case 18:
			Lab18();
			break;
		case 19:
			Lab19();
			break;
		case 20:
			Lab20();
			break;
		case 21:
			Lab21();
			break;
		case 22:
			Lab22();
			break;
		case 23:
			Lab23();
			break;
		case 24:
			Lab24();
			break;
		case 25:
			Lab25();
			break;
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