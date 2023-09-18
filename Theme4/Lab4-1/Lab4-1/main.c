#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int countElement(int inputArray[], int elementToCount);
void randArray(int array[]);


int main(void)
{
	srand(time(0));
	int inputInt;
	int arr1[MAX];
	randArray(arr1); // generate an array with random numbers
	printf("Enter an integer to search for: "); // ask user for an integer to look for in the array
	scanf_s("%d", &inputInt);
	int occuranceInt = countElement(arr1, inputInt); // counting how many times the chosen integer occurs
	printf("The number %d occurs %d times", inputInt, occuranceInt);

	return 0;
}

void randArray(int array[]) //Fill an array of size 10 with random numbers.
{
	for (int i = 0; i < MAX; i++)
	{
		array[i] = rand() % MAX + 1;
		printf("Number: %d\n", array[i]);
	}
}

int countElement(int inputArray[], int elementToCount)
{
	int count = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (inputArray[i] == elementToCount)
			count++;
	}
	return count;
}