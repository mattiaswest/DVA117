#include <stdio.h>

#define SIZE 100

void mostFrequentNumber(int arr[], int* number, int* frequency, int arrSize);

int main(void)
{
	int input = 0;
	int inputCount = 0;
	int arrInput[SIZE];
	int numberMostFrequent = 0;
	int numberFrequency = 0;
	 
	printf("Please enter numbers between 0 and 1000, both of these included (max 100 numbers). End with a negative number.\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("Number: ");
		scanf("%d", &input);
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
	mostFrequentNumber(arrInput, &numberMostFrequent, &numberFrequency, inputCount);
	printf("The most frequent number of the array is %d, it occurrs %d times", numberMostFrequent, numberFrequency);
	return 0;
}

void mostFrequentNumber(int arr[], int* number, int* frequency, int arrSize)
{
	int occurrences = 0;

	for (int i = 0; i < arrSize; i++)
	{
		occurrences = 0;
		for (int j = 0; j < arrSize; j++)
		{
			if (arr[j] == arr[i])
				occurrences++;
		}
		if (occurrences > *frequency)
		{
			*frequency = occurrences;
			*number = arr[i];
		}
	}
}