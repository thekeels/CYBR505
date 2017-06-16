#include <stdio.h>
#include <math.h>
void BaseChange(char binary[],int);
void printdashes(void);
int get_decimal(void);

int main()
{
	int n;
	char binary[4];
	// Get a decimal integer from the user
	n = get_decimal();
	// Validity check on the value of the input
	while (n < 2 || n > 15)
	{
		printdashes();
		printf("\nThis number is outside the acceptable range!\n\n");
		n = get_decimal();
	}
	// Convert the decimal to binary
	BaseChange(binary,n);
	//Print the binary conversion
	printdashes();
	printf("\nThe number %d in binary is:\t\t%c%c%c%c\n", n, binary[3], binary[2], binary[1], binary[0]);
	printdashes();
	getchar();
	getchar();
	return (0);
}
/***************************************/
//Basechange --- converts a decimal value to binary, stored as char
// Input: binary string memory address, decimal value
// Output: char array with binary representation of the decimal value
/***************************************/
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
/***************************************/
//printdashes ---prints a line of ====
// Input: none
// Output: prints a line of dashes
/***************************************/
void printdashes()
{
	printf("============================================================\n");
}
/***************************************/
//get_decimal --- reads a decimal value from the user
// Input: none
// Output: decimal value
/***************************************/
int get_decimal(void) {
	int n;
	printdashes();
	printf("Input a number in decimal form:\t\t");
	scanf_s("%d", &n);
	return n;
}
