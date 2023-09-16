#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void intToChar(int in);
int randomNumber(int min, int max);
void print(int thousand, int hundred, int ten, int one);

int main(void)
{
	int min, max, number, numberOrg;
	int thousand = 0, hundred = 0, ten = 0, one = 0;
	do {
		printf("Enter min value: \n");
		scanf_s("%d", &min);
	} while (min < 0 || min>1000);
	
	do {
		printf("Enter max value: \n");
		scanf_s("%d", &max);
	} while (max < 0 || max>1000 || max < min);
	srand(time(NULL));
	number = randomNumber(min, max);
	numberOrg = number;

	one = number % 10;
	number /= 10;
	ten = number % 10;
	number /= 10;
	hundred = number % 10;
	number /= 10;
	thousand = number % 10;
	
	printf("The random number is: ");
	print(thousand, hundred, ten, one);
	printf("(%d)\n", numberOrg);
	return 0;
}

void intToChar(int in)
{
	switch (in)
	{
	case 0: printf("Zero "); break;
	case 1: printf("One "); break;
	case 2: printf("Two "); break;
	case 3: printf("Three "); break;
	case 4: printf("Four "); break;
	case 5: printf("Five "); break;
	case 6: printf("Six "); break;
	case 7: printf("Seven "); break;
	case 8: printf("Eight "); break;
	case 9: printf("Nine "); break;
	default: printf("Invalid input"); break;
	}
}

void print(int thousand, int hundred, int ten, int one)
{
	if (thousand == 1)
	{
		intToChar(thousand);
		intToChar(hundred);
		intToChar(ten);
		intToChar(one);
	}
	else
	{
		if (hundred > 0)
		{
			intToChar(hundred);
			intToChar(ten);
			intToChar(one);
		}
		else
		{
			if (ten > 0)
			{
				intToChar(ten);
				intToChar(one);
			}
			else
				intToChar(one);
		}
	}
}

int randomNumber(int min, int max)
{
	return rand() % (max-min+1)+min;
}