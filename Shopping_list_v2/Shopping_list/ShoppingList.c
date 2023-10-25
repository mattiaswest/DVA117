#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // For dynamic memory (lab 7)


void addItem(struct ShoppingList* list)
{
	if (list->itemList == NULL)
	{
		list->itemList = (struct GroceryItem*)calloc(1, sizeof(struct GroceryItem));
		if (list->itemList == NULL)
		{
			printf("ERROR!");
			return;
		}
	}
	else
	{
		if (!reallocateMemory(&list->itemList, list->length + 1))
		{
			printf("Failed to allocate memory");
		}
	}

	int i = list->length;
	while (getchar() != '\n');
	
	printf("Name of item: ");
	fgets(list->itemList[i].productName, MAX, stdin);
	int len = strlen(list->itemList[i].productName);
	list->itemList[i].productName[len - 1] = '\0';

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
	printf("List lenght: %d", list->length);
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
		if (inList(entry, list) != 1) {
			printf("Your entry is not on the list!\n");
		}
	} while (inList(entry, list) != 1);
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
	int entry;
	if (list->length > 0) {
		printf("What item would you like to remove?: ");
		do {
			scanf_s("%d", &entry);
			if (inList(entry, list) != 1)
				printf("Entry not in list!");
		} while (inList(entry, list) != 1);

		if (entry == list->length)
		{
			list->length = list->length - 1;
		}
		else
		{
			for (int i = entry; i < list->length; i++)
			{
				list->itemList[i - 1] = list->itemList[i];
			}
			list->length = list->length - 1;
		}
	}
	else
		printf("Your list is empty, nothing to remove!");
}

void saveList(struct ShoppingList* list)
{
	if (list->itemList == NULL)
	{
		printf("Can't save empty list!");
	}
	else
	{
		char fileName[MAX];
		while (getchar() != '\n');
		printf("Enter name of shopping list: ");
		fgets(fileName, 20, stdin);
		fileName[strlen(fileName) - 1] = '\0';
		FILE* fp = fopen(fileName, "w");
		if (fp == NULL)
		{
			printf("Could not create file \n");
			return; 
		}
		printf("Writing to file ...\n");
		fprintf(fp, "%d\n", list->length);

		for (int i = 0; i < list->length; i++)
		{
			fprintf(fp, "%s %.1f %s\n", list->itemList[i].productName, 
				list->itemList[i].amount, list->itemList[i].unit);
		}
		fclose(fp);
	}

}

void loadList(struct ShoppingList* list)
{
	int i = 0;
	char fileName[MAX];
	while (getchar() != '\n');
	fgets(fileName, MAX, stdin);
	fileName[strlen(fileName) - 1] = '\0';
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("Could not open file");
		return;
	}
	fscanf_s(fp, "%d", &list->length);
	if (list->itemList != NULL)
	{
		free(list->itemList);
		list->itemList = NULL;
	}
	list->itemList = (struct GroceryItem*)calloc(list->length, sizeof(struct GroceryItem));
	if (list->itemList == NULL)
	{
		printf("ERROR!");
		return;
	}
	for (i = 0; i < list->length; i++)
	{
		fscanf(fp, "%s ", list->itemList[i].productName);
		fscanf(fp, "%f ", &list->itemList[i].amount);
		fscanf(fp, "%s\n", list->itemList[i].unit);
	}
	fclose(fp);
}

int isPositive(float number)
{
	if (number > 0)
		return 1;
	else
		return 0;
}

int inList(int entry, struct ShoppingList* list)
{
	if (isPositive(entry) != 1 || entry > list->length)
		return 0;
	else
		return 1;
}

int reallocateMemory(struct GroceryItem** oldMemory, int newMemory) {
	struct GroceryItem* temp = (struct GroceryItem*)realloc(*oldMemory, sizeof(struct GroceryItem) * newMemory);
	if (temp != NULL)
	{
		*oldMemory = temp;
		return 1;
	}
	else
	{
		printf("ERROR");
		free(temp);
		return 0;
	}
}
