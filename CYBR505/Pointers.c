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
	printf("%d\n", *A);
//	crazy_function(A);
//	printf("%d\n", *A); 
	basic_function(*A);
	printf("%d", *A);
	getchar();
	getchar();
	return(0);
}