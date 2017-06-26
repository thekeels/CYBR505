#include <stdio.h>

void split(int Array[20], int positive[20], int negative[20]);
void printArrays(int positive[20], int negative[20]);

int main() {

	int Array[20] = { 1,2,3,4,5,6,7,8,9,10,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10 }; // Initialize the array
	int positive[20], negative[20]; // Create variables for the split positive and negative arrays
	split(Array, positive, negative); // Split the array into positive and negative values
	printArrays(positive, negative); // Print the arrays
	getchar();
	getchar();
	return;
}

//Function -- split -- fulls out the positive values and stores them in "positive", stores negative values in "negative"
// Input: memory addresses of arrays
// Output: stored values in the positive and negative arrays
void split(int Array[20], int positive[20], int negative[20])
{
	for (int i = 0; i < 20; i++)
	{
		if (Array[i] >= 0) 
		{
			positive[i] = Array[i]; // If positive, store the values of Array in positive
		}
		else
		{
			negative[i] = Array[i]; // If negative, store the values of Array in negative
		}
	}
}
// Function -- printArrays -- prints the arrays
// Input: memory address of the arrays
// Output: prints the arrays
void printArrays(int positive[20], int negative[20])
{

	printf("Positive Array\t\tNegative Array\n");
	for (int i = 0; i < 20; i++)
	{
		printf("%d\t\t\t%d\n", positive[i], negative[i]);
	}
	
}