#include <stdio.h>

int main()

{
	char Input[32];
	char Output[32];
	int i = 0;
	int length;
	printf("Please enter the input string in uppercase: ");
	// Read in the input string
	fgets(Input, 32, stdin);
	// Convert the input string to lowercase by adding 32 to the ASCII value
	while(Input[i] != '\n')
	{
		if (Input[i] < 100)
		{
			Input[i] += 32;
		}
		else;
		i++;
	}
	length = i;
	printf("\nThe lowercase string is: ");
	// Print the lowercase string
	for (i = 0; i < length; i++)
	{
		printf("%c", Input[i]);
	}

	getchar();
	getchar();
	return 0;
}
