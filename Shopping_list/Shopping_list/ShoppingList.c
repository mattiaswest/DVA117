#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // For dynamic memory (lab 7)


void addItem(struct ShoppingList* list)
{
	printf("Items in list: %d\n", list->length);
	while (getchar() != '\n');
	int i = list->length;
	if (i < 5) {
		printf("Name of item: ");
		fgets(list->itemList[i].productName, MAX, stdin);
		list->itemList[i].productName[strlen(list->itemList[i].productName) - 1] = "\0";

		do {
			printf("Amount: ");
			scanf_s("%f", &list->itemList[i].amount);
			if (isPositive(list->itemList[i].amount) == 0) {
				printf("Amount can't be negative!\n");
			}
		} while (isPositive(list->itemList[i].amount) != 1);
		while (getchar() != '\n');

		printf("Unit: ");
		fgets(list->itemList[i].unit, MAX, stdin);
		list->itemList[i].unit[strlen(list->itemList[i].unit) - 1] = '\0';

		list->length = list->length + 1;
	}
	else
		printf("\n--------------------\nThe shopping list is full!\n--------------------\n");
}

void printList(struct ShoppingList* list)
{
	if (list->length != 0) {
		for (int i = 0; i < list->length; i++)
		{
			printf("%d. %-20s\t%.1f\t%5s\n", (i+1), list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
		}
	}
	else
		printf("Your list is empty!");
}

void editItem(struct ShoppingList* list)
{
	int entry;
	float amountNew;
	printf("Which entry would you like to edit?: \n");
	do {
		scanf_s("%d", &entry);
		if (isPositive(entry) != 1 || entry > list->length)
			printf("Your entry is not on the list!\n");
	} while (isPositive(entry) != 1 || entry > list->length);
	printf("New amount for %s: ", list->itemList[entry-1].productName);
	do {
		scanf_s("%f", &amountNew);
		if (isPositive(amountNew) == 0)
		{
			printf("Amount can't be negative!");
		}
	} while (isPositive(amountNew) != 1);

	list->itemList[entry - 1].amount = amountNew;
}

void removeItem(struct ShoppingList* list)
{

}

/*saveList och loadList implementeras i laboration 7*/
void saveList(struct ShoppingList* list)
{

}

void loadList(struct ShoppingList* list)
{

}

int isPositive(float number)
{
	if (number > 0)
		return 1;
	else
		return 0;
}

