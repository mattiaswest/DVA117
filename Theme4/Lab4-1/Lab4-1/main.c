#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int countElement(int inputArray[], int arraySize, int elementToCount);

int randArray() //Fill an array of size 10 with random numbers.
{
	srand(time(0));
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 10 + 1;
		printf("%d", arr[i]);
	}
	return arr;
}

int main(void)
{
	return 0;
}