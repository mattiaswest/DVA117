#include <stdio.h>

float currencyExchange(int amountSek, float exchangeRate)
{
	return amountSek * exchangeRate;
}

int main (void)
{
	int sek;
	printf("Enter SEK: ");
	scanf_s("%d", &sek);
	float sekConverted = currencyExchange(sek, 1.5);
	printf("This converts to %.1f", sekConverted);
	return 0;
}