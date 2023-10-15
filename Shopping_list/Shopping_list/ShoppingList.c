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
			if (list->itemList[i].amount < 0) {
				printf("Your amount can't be negative!\n");
			}
		} while (list->itemList[i].amount < 0);
		while (getchar() != '\n');

		printf("Unit: ");
		fgets(list->itemList[i].productName, MAX, stdin);
		list->itemList[i].productName[strlen(list->itemList[i].productName) - 1] = '\0';

		list->length = list->length + 1;
	}
	else
		printf("\n--------------------\nThe shopping list is full!\n--------------------\n");
}

void printList(struct ShoppingList* list)
{

}

void editItem(struct ShoppingList* list)
{

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

