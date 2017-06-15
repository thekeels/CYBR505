#include <stdio.h>
#include <math.h>
char* BaseChange(int);
void printdashes(void);

int main()
{
	int n;
	int sentinel = 1;
	char* binary;
	printdashes();
	
	printf("Input a number in decimal form:\t\t");
	scanf_s("%d", &n);
	while (sentinel == 1)
	{
		if (2 < n && n < 15)
		{
			binary = BaseChange(n);
			sentinel = 0;
		}
		else
		{
			printdashes();
			printf("\nThis number is outside the acceptable range!\n\n");
			printdashes();
			printf("Input a number in decimal form:\t\t");
			scanf_s("%d", &n);
		}
	}
	//printdashes();
	printf("\nThe number %d in binary is:\t\t%c%c%c%c", n, binary[3], binary[2], binary[1], binary[0]);
	getchar();
	getchar();
	return (0);
}

char* BaseChange(int n)
{
	int num;
	char binary[4];
	for (int i = 3; i > -1; i--)
	{
		num = pow(2, i);
		if (n - num >= 0)
		{
			n -= num;
			binary[i] = '1';
		}
		else
		{
			binary[i] = '0';
		}

	}
	return binary;
}

void printdashes()
{
	printf("============================================================\n");
}