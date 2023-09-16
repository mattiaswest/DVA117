#include <stdio.h>
int yearsMaxPopulation(int current, int max, float increase);

int main(void)
{
	int popCurrent = 0;
	int popMax = 0;
	float popIncrease = 0;
	printf("Enter current population: \n");
	scanf_s("%d", &popCurrent);
	printf("Enter max population: \n");
	scanf_s("%d", &popMax);
	printf("Enter population increase rate: \n");
	scanf_s("%f", &popIncrease);
	int yearsUntilMax = yearsMaxPopulation(popCurrent, popMax, popIncrease);
	printf("Years until max population is reached: %d", yearsUntilMax);

	return 0;
}

int yearsMaxPopulation(int current, int max, float increase)
{
	int year = 0;
	for (current; current < max; current * increase)
	{
		year++;
		current *= increase;
		printf("Year %d population: %d\n", year, current);
	}
	return year;
}