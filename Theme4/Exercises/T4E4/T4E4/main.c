#include <stdio.h>

int main(void)
{
	int j = 0;
	int arr1[3];
	int arr2[3];
	int arrCombined[6];
	printf("Enter 3 digits to fill array 1\n");
	for (int i = 0; i < 3; i++)
	{
		printf("Enter a number: ");
		scanf_s("%d", &arr1[i]);
	}
	printf("Enter 3 digits to fill array 2\n");
	for (int i = 0; i < 3; i++)
	{
		printf("Enter a number: ");
		scanf_s("%d", &arr2[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		arrCombined[j] = arr1[i];
		j++;
	}
	for (int i = 0; i < 6; i++)
	{
		arrCombined[j] = arr2[i];
		j++;
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d", arrCombined[i]);
	}
	