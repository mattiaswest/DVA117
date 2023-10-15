#include <stdio.h>

int main(void)
{
	float priceIncVat;
	int vatPercentage;
	float priceExcVat = 0;
	float vatAmount = 0;

	printf("Enter on article (Including VAT): \n");
	scanf_s("%f", &priceIncVat);
	printf("VAT (percentage as integer): \n");
	scanf_s("%d", &vatPercentage);

	priceExcVat = priceIncVat / (1+((float)vatPercentage/100));
	vatAmount = priceIncVat - priceExcVat;

	printf("Price excluding VAT: %.2f\n", priceExcVat);
	printf("The VAT is: %.2f", vatAmount);
	return 0;
}