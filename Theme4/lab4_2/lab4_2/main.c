#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int isPalindrome(char inputString[]);

int main(void)
{
	char string[SIZE];
	printf("Please enter a word or a sentence: ");
	fgets(string, SIZE, stdin);
	string[strlen(string) - 1] = '\0';
	printf("%d", isPalindrome(string));

	return 0;
}

int isPalindrome(char inputString[])
{
	int j = strlen(inputString) - 1;
	for (int i = 0; i < strlen(inputString)/2; i++)
	{
		if (inputString[i] == inputString[j])
			j--;
		else
			return 0;
	}
	return 1;
}