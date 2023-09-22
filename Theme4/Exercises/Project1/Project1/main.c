#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30
int main(void)
{
	char string[MAX_SIZE];
	char letterInput;
	int printFromIndex = 0;
	printf("Please enter a string: ");
	fgets(string, MAX_SIZE, stdin);
	string[strlen(string) - 1] = '\0';
	printf("Please choose a letter: ");
	scanf_s("%c", &letterInput);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (string[i] == letterInput)
		{
			printFromIndex = string[i];
			break;
		}
	}

	puts(string);
}