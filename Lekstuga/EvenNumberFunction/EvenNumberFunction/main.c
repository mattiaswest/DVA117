#include <stdio.h>

int evenNum(num1)
{
	int res = num1 % 2;
	return res;
}

int main(void)
{
	int numInput = 1;
	while (numInput != 0)
	{
		printf("Please enter a number(type 0 to close program): ");
		scanf_s("%d", &numInput);
		int res = evenNum(numInput);
		if (res == 0)
		{
			printf("\nYour number is even\n");
		}
		else
		{
			printf("\nYour number is odd\n");
		}
		
	}
	return 0;
}