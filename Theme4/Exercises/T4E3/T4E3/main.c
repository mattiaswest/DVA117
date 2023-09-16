#include <stdio.h>
#define SIZE 10

void reverseString(int inputString[], int inputReverse[]);
void printString(int inputString[], int inputReverse[]);

int main(void)
{
	int stringInts[SIZE];
	int stringReverse[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		printf("Enter a number: ");
		scanf_s("%d", &stringInts[i]);
	}
	reverseString(stringInts, stringReverse);
	printString(stringInts, stringReverse);
	return 0;
}

void reverseString(int inputString[], int inputReverse[])
{
	int j = 0;
	for (int i = SIZE-1; i >= 0; i--)
	{
		inputReverse[j] = inputString[i];
		j++;
	}
}

void printString(int inputString[], int inputReverse[])
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t%d\n", inputString[i], inputReverse[i]);
	}
}