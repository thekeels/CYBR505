#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char test[32];
	char test2[] = "Concat";
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
	printf("\nThe entered string was: %s!!\n", test);
	//strcpy(test, test2);
	printf("%s\n", test);
	strncpy(test, test2, 4);
	printf("%s\n", test);

	strncpy(test, test2+1, 4);
	printf("%s\n", test);

	getchar();
	getchar();
	return 0;

}