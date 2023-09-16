#include <stdio.h>
int main()
{
	float price;
	char discount;
	printf("Is the customer a student(S), an employee (E) or a regular customer (R) ");
	scanf_s("%c", &discount);
	printf("Price on ticket: ");
	scanf_s("%f", &price);
	switch (discount)
	{
	case 'E': price = price * 0.9; break; //pris efter 10% rabatt
	case 'S': price = price * 0.8; break; //pris efter 20% rabatt
	case 'R': printf("The price will be calculated without any discount");
		break;
	default: printf("Your input is invalid, the price will be calculated without any discount.");
	}
	price = price * 1.05; //lägger på 5% serviceavgift
	printf("\nTotal price: %.2f", price);
	return 0;
}