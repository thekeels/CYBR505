#include <stdio.h>
#include <math.h>
void BaseChange(char binary[],int);
void printdashes(void);
int get_decimal(void);

int main()
{
	int n;
	char binary[4];
	n = get_decimal();
	//printdashes();
	//printf("Input a number in decimal form:\t\t");
	//scanf_s("%d", &n);
	//while (sentinel == 1)
	while (n < 2 || n > 15)
	{
		printdashes();
		printf("\nThis number is outside the acceptable range!\n\n");
		n = get_decimal();
	}
		BaseChange(binary,n);
	
	printdashes();
	printf("\nThe number %d in binary is:\t\t%c%c%c%c", n, binary[3], binary[2], binary[1], binary[0]);
	getchar();
	getchar();
	return (0);
}

void BaseChange(char binary[], int n)
{
	int num;
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
	return;
}

void printdashes()
{
	printf("============================================================\n");
}

int get_decimal(void) {
	int n;
	printdashes();
	printf("Input a number in decimal form:\t\t");
	scanf_s("%d", &n);
	return n;
}
