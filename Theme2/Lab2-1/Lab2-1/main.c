#include <stdio.h>

int main(void)
{
	int angle;
	printf("Enter a positive angle in full degrees: ");
	scanf_s("%d", &angle);

	if (angle > 0 && angle < 90)
	{
		puts("The angle is accute!");
	}
	else if (angle == 90)
	{
		puts("The angle is orthogonal!");
	}
	else if (angle > 90 && angle <= 180)
	{
		puts("The angle is obtuse!");
	}
	else
	{
		puts("Incorrect value!");
	}
}