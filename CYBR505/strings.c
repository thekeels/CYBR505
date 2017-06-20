#include <stdio.h>

int main()
{
	int i;
	char test[32];
	printf("Enter a string: ");
	fgets(test, 32,stdin);
	printf("\nThe entered string was: %s!!", test);
	
	for (i = 0; i < 32; i++)
	{
		if (test[i] == '\n')
		{
			test[i] = '\0';
		}
		else {}
	} 
	printf("\nThe entered string was: %s!!", test);
	getchar();
	getchar();
	return 0;

}