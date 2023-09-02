/*********************************
Mattias West, mwt23002, 940328-1570
Programmering DVA117
Laboration 1.2
*********************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1;
	int num2;
	int sumNum;
	printf("Please enter a number: \n");
	scanf("%d", &num1);
	printf("That's a great number! Now choose another one: \n");
	scanf("%d", &num2);
	sumNum = num1 + num2;
	printf("If we add your first number %d with your second number %d, the sum is %d", num1, num2, sumNum);
	return 0; 
}