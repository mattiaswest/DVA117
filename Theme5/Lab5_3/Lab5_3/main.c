#include <stdio.h>

#define SIZE 100

void mostFrequentNumber(int* arr[]);

int main(void)
{
	int input = 0;
	int inputCount = 0;
	int arrInput[SIZE];
	int* numberOccurance;
	int* numberMostFrequent;
	printf("Please enter numbers between 0 and 1000, both of these included (max 100 numbers). End with a negative number.\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("Number: ");
		scanf_s("%d", &input);
		if (input >= 0 && input <= 1000)
		{
			arrInput[i] = input;
			inputCount++;
		}
		else if (input < 0)
			break;
		else
			i--;
	}
	return 0;
}

void mostFrequentNumber(int* arr[])
{

}
