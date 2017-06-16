#include <stdio.h>

int main()
{
	int i, swap;
	int list1[5], list2[5];
	printf("Please enter values to list1 array\n");
	for(i=0;i<5;i++)
	{
		scanf_s("%d", list1 + i);
	}
	printf("Please enter values to list2 array\n");
	for (i = 0; i<5; i++)
	{
		scanf_s("%d", list2 + i);
	}
	printf("List1 and List2 before swap\n");
	printf("List1\t\t\tList2\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d\t\t\t%d\n", list1[i], list2[i]);
	}
	for (i = 0; i < 5; i++)
	{
		swap = list1[i];
		list1[i] = list2[i];
		list2[i] = swap;
	}
	printf("List1 and List2 after swap\n");
	printf("List1\t\t\tList2\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d\t\t\t%d\n", list1[i], list2[i]);
	}
	getchar();
	getchar();
	return 0;
}