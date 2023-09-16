#include <stdio.h>
#include <math.h>

int squareRoot(float *pNumber);

int main(void)
{
	float number;
	int isPositive;
	printf("Enter a number: ");
	scanf_s("%f", &number);
	isPositive = squareRoot(&number);

	if (isPositive)
		printf("The square root of your number is %.2f", number);
	else
		printf("It is not possible to calculate the square root of a negative number");

	return 0;
}

int squareRoot(float *pNumber)
{
	if (*pNumber >= 0)
	{
		*pNumber *= *pNumber;
		return 1;
	}
	else
		return 0;
}