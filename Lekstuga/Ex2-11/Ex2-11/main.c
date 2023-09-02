#include <stdio.h>
#include <math.h>

int main(void)
{
	int input;
	printf("Enter a number between 1 and 5");
	scanf_s("%d", &input);
	if (input >= 0 && input < 6)
	{
		for (int i = 0; i < input + 1; i++)
		{
			printf("%d           %d\n", i, (int)pow(3, i));
		}
	}
	return 0;
}