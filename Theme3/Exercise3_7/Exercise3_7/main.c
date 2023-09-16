#include <stdio.h>
float totalPrice(float price, char discount);

int main()
{
	float price;
	char discount;
	printf("Is the customer a student(S), an employee (E) or a regular customer (R) ");
	scanf_s("%c", &discount);
	printf("Price on ticket: ");
	scanf_s("%f", &price);
	
	price = totalPrice(price, discount);

	price = price * 1.05;
	printf("\nTotal price: %.2f\n", price);
	return 0;
}

float totalPrice(float price, char discountGroup)
{
	switch (discountGroup)
	{
		case 'E': price = price * 0.9; break; //pris efter 10% rabatt
		case 'S': price = price * 0.8; break; //pris efter 20% rabatt
		case 'R': printf("The price will be calculated without any discount"); break;
		default: printf("Your input is invalid, the price will be calculated without any discount.");
	}
	return price;
}