#include <stdio.h>

int main(void)
{
	int numberInput;
	int numberLow;
	int numberHigh;
	int numberSum;
	int numberCounter; 
	int runProgram = 1;
	printf("Welcome!\nEnter a negative number to exit input and print the result\n\n");

	while (runProgram == 1) { //This loop allows the user to choose how long they want the program to run
		numberCounter = 0;
		numberInput = 0;
		numberSum = 0;
		numberLow = 0;
		numberHigh = 0;

		while (numberInput >= 0)
		{
			printf("Give number: ");
			scanf_s("%d", &numberInput);

			if (numberInput > 0)
			{
				numberCounter++; //Keeping track of number of inputs
				numberSum = numberSum + numberInput; //Adding all inputs together
			}
			if ((numberInput < numberLow && numberInput > 0) || numberLow == 0)
			{
				numberLow = numberInput;
			}
			else if (numberInput > numberHigh)
			{
				numberHigh = numberInput;
			}
		}
		if (numberCounter == 0)
		{
			printf("You didn't enter any positive numbers, nothing to output.");
		}
		else
		{
			printf("The smallest number is: %d\n", numberLow);
			printf("The biggest number is: %d\n", numberHigh);
			printf("The sum of the numbers is: %d\n", numberSum);
			printf("The average value is: %f\n", (float)numberSum / numberCounter); //Calculating the mean value by dividing the total sum with number of inputs
		}
		do
		{
			printf("\n\n\nWould you like to run the program again? (1=yes 0=no)"); //Asking user if they want to continue, 1 will restart initial while loop.
			scanf_s("%d", &runProgram);
		} while (runProgram != 0 && runProgram != 1);
	}
	printf("Exiting program, buh-bye!");
	return 0;
}