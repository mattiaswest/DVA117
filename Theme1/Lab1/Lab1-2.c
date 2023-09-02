#include <stdio.h>

int main(void)
{
    int num1, num2, sum;
    printf("Please enter a number: ");
    scanf("%d", &num1);
    printf("That's a great number! Now choose another one: ");
    scanf("%d", &num2);
    sum = num1+num2;
    print("If you take your first number %d and add it with your second number %d, the sum is %d", num1, num2, sum);
    return 0;
}