#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int isPalindrome(char inputString[]);
void cleanPalindrome(char inputString[], char stringClean[]);
void lowerPalindrome(char stringClean[]);

int main(void)
{
	int palindrome = 0;
	int run = 1;
	char string[SIZE];
	char cleanString[SIZE];
	do
	{
		printf("Please enter a word or a sentence: ");
		fgets(string, SIZE, stdin);
		string[strlen(string) - 1] = '\0';
		cleanPalindrome(string, cleanString);
		lowerPalindrome(cleanString);
		palindrome = isPalindrome(cleanString);
		if (palindrome)
			printf("\n\nThis IS a palindrome!\n\n");
		else
			printf("\n\nThis is NOT a palindrome!\n\n");
		do
		{
			printf("Do you want to enter another sentence? (1=yes, 0=no)");
			scanf_s("%d", &run);
			while (getchar() != '\n');
		} while (run != 0 && run != 1);
	} while (run == 1);

	return 0;
}

int isPalindrome(char inputString[])
{
	int j = strlen(inputString) - 1;
	int l = strlen(inputString);
	for (int i = 0; i < l / 2; i++)
	{
		if (inputString[i] == inputString[j])
			j--;
		else
			return 0;
	}
	return 1;
}

void cleanPalindrome(char inputString[], char stringClean[])
{
	int j = 0;
	int l = strlen(inputString);
	for (int i = 0; i < l; i++)
	{
		if (isalpha(inputString[i]) != 0)
		{
			stringClean[j] = inputString[i];
			j++;
		}
	}
	stringClean[j] = '\0';
}

void lowerPalindrome(char stringClean[])
{
	int l = strlen(stringClean);
	for (int i = 0; i < l; i++)
	{
		stringClean[i] = tolower(stringClean[i]);
	}
}