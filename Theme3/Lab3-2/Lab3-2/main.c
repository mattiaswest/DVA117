#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber()
{
	srand(time(0));
	return rand() % 100 + 1;
}

int playerGuess()
{
	int guessInput = 0;
	int answer = randomNumber();
	int i = 0;
	do
	{
		scanf_s("%d", &guessInput);
		if (guessInput < answer)
		{
			printf("Your guess is too low, try again!\n");
		}
		else if (guessInput > answer)
		{
			printf("Your guess is too high, try again!\n");
		}
		else
		{
			printf("Congratulations, that is correct!\n");
		}
		i++;
	} while (guessInput != answer);
	return i;
}

int main(void)
{
	printf("I'm thinking of a number between 1 and 100, guess which!\n\n");
	int totalGuesses = playerGuess();
	printf("You made %d attempts", totalGuesses);
	return 0;
}