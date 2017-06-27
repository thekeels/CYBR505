#include <stdio.h>

void split(int Array[], int positive[], int negative[], int index[]);
void printArrays(int positive[], int negative[], int index[]);

int main() {

	int index[2]; //Create an index to count the number of pos/neg numbers
	int Array[20] = { -11,12,-3,-45,-35,36,37,98,-19,-10,1,-21,-3,4,-15,6,-17,-8,-19,-10 }; // Initialize the array
	// int Array[20] = { 1,2,3,4,5,6,7,8,9,10,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10 }; // Initialize the array
	int positive[20], negative[20]; // Create variables for the split positive and negative arrays
	split(Array, positive, negative, index); // Split the array into positive and negative values
	printArrays(positive, negative, index); // Print the arrays
	getchar();
	getchar();
	return;
}

//Function -- split -- pulls out the positive values and stores them in "positive", stores negative values in "negative"
// Input: memory addresses of arrays and index
// Output: stored values in the positive and negative arrays, and the number of pos/neg values
void split(int Array[], int positive[], int negative[], int index[])
{
	index[0] = index[1] = 0;
	for (int i = 0; i < 20; i++)
	{
		if (Array[i] >= 0) 
		{
			positive[index[0]] = Array[i]; // If positive, store the values of Array in positive
			index[0]++; //Increment the counter of positive values
		}
		else
		{
			negative[index[1]] = Array[i]; // If negative, store the values of Array in negative
			index[1]++;
		}
	}
	return;
}
// Function -- printArrays -- prints the arrays
// Input: memory address of the arrays
// Output: prints the arrays
void printArrays(int positive[], int negative[], int index[])
{

	printf("Positive Array\t\tNegative Array\n");
	for (int i = 0; i < index[0] || i < index[1]; i++) // Do this loop if either of the indexes is greater than i
	{
		if (index[0] > i) // Keep printing positive values until you reach the index value
		{
			printf("%d\t\t\t", positive[i]);
		}
		else
		{
			printf("  \t\t\t"); //Once you reach the index value, stop printing values
		}
		if (index[1] > i)
		{
			printf("%d\n", negative[i]); // Keep printing negative values until you reach the index value
		}
		else
		{
			printf("  \n"); // Once you reach the index value, stop printing values
		}
	}
	
}