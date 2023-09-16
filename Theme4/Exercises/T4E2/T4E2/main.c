#include <stdio.h>
#define SIZE 11

int main(void)
{
	char myString[SIZE];
	printf("Enter a string: ");
	fgets(myString, SIZE, stdin);
	printf("%s", myString);
}