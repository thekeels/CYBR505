#include<stdio.h>
int crazy_function(int *x)
{
	int y = 10;
	*x = y;
	return 0;

}
int basic_function(int x)
{
	int y = 10;
	x = y;
	return 0;

}
int main()
{
	int a;
	a = 15;
	int *A;
	A = &a;
	int array1[] = { 1,2,3,4,5 };

	printf("%d\n", *A);
//	crazy_function(A);
//	printf("%d\n", *A); 
	basic_function(*A);
	printf("%d\n", *A);
	int i;
	for (i=0;i<5;i++)
	printf("%d\n", array1[i]);
	for (i=0;i<5;i++)
		printf("%d\n", *array1+i);

	getchar();
	getchar();
	return(0);
}