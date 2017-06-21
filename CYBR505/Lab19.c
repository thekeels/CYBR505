#include <stdio.h>
#define len 32

char * Encrypt_Decrypt(char[], int, int);

int main() {

	int index;
	char * Encrypted;
	char * Decrypted;
	char Input[len];
	char key = 10;

	printf("Enter your string: ");
	//Read in a string
	fgets(Input, len, stdin);
	//Find length of the string
	index = strlen(Input);
	//Print the enncrypted string
	printf("\nThe encrypted string is: ");
	Encrypted = Encrypt_Decrypt(Input, key, index);
	//Print the decrypted string
	printf("\n\nThe decrypted string is: ");
	Decrypted = Encrypt_Decrypt(Encrypted, key, index);

	getchar();
	getchar();
	return 0;
}
//Encrypt_Decrypt -- performs XOR encryption/decryption of a string
//Input:  Memory address of the input string, the key, length of the input string
//Output: Memory address of the output string
char * Encrypt_Decrypt(char Input[], int key, int index)
{
	int i;
	static char Output[len];
	for (i = 0; i < index; i++)
	{
		Output[i] = (Input[i] ^ key);
		printf("%c", Output[i]);
	}
	return Output;
}
