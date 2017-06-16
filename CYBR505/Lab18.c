#include <stdio.h>

void create_array(int[], int);
void swap_array(int[],int[]);
void print_array(int[], int[]);

int main()
{
	int i, swap, n;
	int list1[50], list2[50];
	printf("Please enter the number or elements of the array, n: ");
	scanf_s("%d", &n);
	create_array(list1, n);
	create_array(list2, n);

	printf("List1 and List2 before swap\n");
	print_array(list1, list2);

	swap_array(list1, list2);
	
	printf("List1 and List2 after swap\n");
	print_array(list1, list2);

	getchar();
	getchar();
	return 0;
}

void create_array(int list1[],int n) {
	int i;
	printf("Please enter values to list1 array\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", list1 + i);
	}
}

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
void print_array(int list1[], int list2[])
{
	printf("List1\t\t\tList2\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t\t\t%d\n", list1[i], list2[i]);
	}
}