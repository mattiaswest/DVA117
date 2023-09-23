#include <stdio.h>

int main(void)
{
	int morseValue;
	printf("Please enter a number between 0 and 5: ");
	scanf_s("%d", &morseValue);
	do
	{
		printf("The number is outside of the given range!\n");
		scanf_s("%d", &morseValue);
	} while (morseValue < 0 || morseValue > 5);

	switch (morseValue)
	{
		case 0: puts("-----"); break;
		case 1: puts(".----"); break;
		case 2: puts("..---"); break;
		case 3: puts("...--"); break;
		case 4: puts("....-"); break;
		case 5: puts("....."); break;
	}
	return 0;
}