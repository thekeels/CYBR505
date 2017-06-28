#include <stdio.h>

int power(int x, int y);
int main()
{
	int out;
	int x = 3;
	int y = 2;
	out = power(x, y);
	return 0;
	
}

int power(int x, int y)
{
	int result = 1;
	if (y == 1)
		return x;
	for (int i = 1; i <= y; i++)
		result = x*result;
	return result;
}