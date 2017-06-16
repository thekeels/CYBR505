#include <stdio.h>

void create_array(int[], int);
void swap_array(int[],int[]);
void print_array(int[], int[]);

int main()
{
	int i, swap, n;
	int list1[9], list2[9];
	//Request size of the array
	printf("Please enter the number or elements of the array, 2 < n < 10: ");
	scanf_s("%d", &n);
	//Validity check on size of the array
	while (n < 2 || n>10)
	{
		printf("Error, outside the valid range, try again\n");
		scanf_s("%d", &n);
	}
	//Create the arrays
	create_array(list1, n);
	create_array(list2, n);
	//Print the arrays before the swap
	printf("List1 and List2 before swap\n");
	print_array(list1, list2);
	//Swap the array values
	swap_array(list1, list2);
	//Print the arrays after the swap
	printf("List1 and List2 after swap\n");
	print_array(list1, list2);

	getchar();
	getchar();
	return 0;
}
/***************************************/
//create_array --- creates an array of size n, determined by user input
// Input: array memory address, size of array
// Output: array with n elements filled in
/***************************************/
void create_array(int list1[],int n) {
	int i;
	printf("Please enter values to list1 array\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", list1 + i);
	}
}
/***************************************/
//swap_array --- swaps the contents of arrays list1 and list2
// Input: memory addresses of list1 and list2
// Output: swapped contents of list1 and list2
/***************************************/
void swap_array(int list1[],int list2[])
{
	int swap;
	for (int i = 0; i < 5; i++)
	{
		swap = list1[i];
		list1[i] = list2[i];
		list2[i] = swap;
	}
}
/***************************************/
//print_array --- prints the contents of arrays list1 and list2
// Input: memory addresses of list1 and list2
// Output: prints contents of list1 and list2
/***************************************/
void print_array(int list1[], int list2[])
{
	printf("List1\t\t\tList2\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t\t\t%d\n", list1[i], list2[i]);
	}
}