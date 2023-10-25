#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<stdlib.h> // For dynamic memory (lab 7)
#include<string.h>
#include <stdbool.h>
void addItem(struct ShoppingList* list)
{
	if (list->length == 0) {
		list->itemList = (struct GroceryItem*)malloc(1 * sizeof(struct GroceryItem));
		if (list->itemList == NULL)
		{
			printf("error");
		}
	}
	else
	{

		if (!reallocateMemory(&list->itemList, list->length + 1)) {
			printf("Failed to reallocate memory!");
			return;
		}

	}




	getchar();
	int i = list->length;


	printf("Add an item: ");
	fgets(list->itemList[i].productName, MAXNAME, stdin);
	list->itemList[i].productName[strcspn(list->itemList[i].productName, "\n")]
		= '\0';
	printf("Amount: ");
	do
	{
		scanf("%f", &list->itemList[i].amount);
	} while (noNegativeNumbersAllowed(list->itemList[i].amount) == false);
	getchar();
	printf("Unit: ");
	fgets(list->itemList[i].unit, MAXNAME, stdin);
	list->itemList[i].unit[strcspn(list->itemList[i].unit, "\n")] = '\0';
	list->length = list->length + 1;



}


void printList(struct ShoppingList* list)
{
	if (list->length == 0)
	{
		printf("No items in cart!");
	}

	for (int i = 0; i < list->length; i++) {
		printf("%d.  %-20s\t %.2f\t %s\n", i + 1, list->itemList[i].productName,
			list->itemList[i].amount, list->itemList[i].unit);


	}
}
void editItem(struct ShoppingList* list)
{
	int editAmount;
	if (list->length == 0)
	{
		printf("No items in cart!");

	}

	for (int i = 0; i < list->length; i++) {
		printf("%d.  %-20s\t %.2f\t %s\n", i + 1, list->itemList[i].productName,
			list->itemList[i].amount, list->itemList[i].unit);
	}
	if (list->length > 0)
	{
		do
		{
			printf("Select which item to edit: ");
			scanf("%d", &editAmount);
			if (list->length < editAmount || editAmount < 0)
			{
				printf("Number %d does not exist in the list!\n", editAmount);
			}
		} while (editAmount > list->length || editAmount < 0);

		do
		{
			printf("Edit amount of %s: ", list->itemList[editAmount -
				1].productName);
			scanf("%f", &list->itemList[editAmount - 1].amount);
		} while (noNegativeNumbersAllowed(list->itemList[editAmount - 1].amount) ==
			false);
	}
}
void removeItem(struct ShoppingList* list)
{
	int removeItem;
	if (list->length == 0)
	{
		puts("No items in cart!");
	}
	for (int i = 0; i < list->length; i++) {
		printf("%d.  %-20s\t %.2f\t %s\n", i + 1, list->itemList[i].productName,
			list->itemList[i].amount, list->itemList[i].unit);
	}
	if (list->length > 0)
	{
		//Do-While kör tills användaren matar in ett positivt tal, talet måste vara inom intervallet

		do
		{
			printf("Select item to remove: ");
			scanf_s("%d", &removeItem);
			if (list->length < removeItem || removeItem <= 0)
			{
				printf("Number %d does not exist in the list!\n", removeItem);
			}
		} while (removeItem <= 0 || removeItem > list->length);


		if (removeItem != list->length || removeItem < list->length)
		{
			for (int i = removeItem; i < list->length; i++)
			{
				list->itemList[i - 1] = list->itemList[i];
			}

			list->length = list->length - 1;

		}

		if (removeItem == list->length)
		{

			list->length = list->length - 1;
		}
	}
}

void saveList(struct ShoppingList* list)
{
	if (list->length == 0)
	{
		printf("Can't save an empty list!");
		return;
	}
	else
	{

		char fileName[20];
		getchar();
		printf("Enter the name of your shoppinglist: ");
		fgets(fileName, 20, stdin);
		fileName[strlen(fileName) - 1] = '\0';
		FILE* fp = fopen(fileName, "w");
		if (fp == NULL)
		{
			printf("Could not create file \n");
			return;
		}
		printf("Currently writing to file... \n");
		fprintf(fp, "%d\n", list->length);

		for (int i = 0; i < list->length; i++)
		{
			fprintf(fp, "%d.  %-20s\t %.2f\t %s\n", i + 1, list->itemList[i].productName,
				list->itemList[i].amount, list->itemList[i].unit);
		}
		fclose(fp);
	}
}
void loadList(struct ShoppingList* list)
{

	int trashTemp[5], tempLength, i;
	char fileName[50];
	struct GroceryItem* temp;

	if (list->length == 0)
	{
		getchar();
		printf("Enter Filename: ");
		fgets(fileName, 20, stdin);
		fileName[strlen(fileName) - 1] = '\0';

		FILE* fp = fopen(fileName, "r");
		if (fp == NULL)
		{
			printf("Can't open file!");
			return;
		}



		free(list->itemList);
		fscanf(fp, "%d", &list->length);
		fgetc(fp);
		list->itemList = (struct GroceryItem*)malloc(list->length * sizeof(struct GroceryItem));
		if (list->itemList == NULL)
		{
			printf("Can't allocate memory!");
		}
		for (int i = 0; i < list->length; i++)
		{

			fgets(trashTemp, 5, fp);
			trashTemp[strlen(trashTemp) - 1] = '\0';
			fgets(list->itemList[i].productName, MAXNAME, fp);
			list->itemList[i].productName[strlen(list->itemList[i].productName) - 1] = '\0';
			fscanf(fp, "%f\n", &list->itemList[i].amount);
			fgets(list->itemList[i].unit, MAXNAME, fp);
			list->itemList[i].unit[strlen(list->itemList[i].unit) - 1] = '\0';
		}

		fclose(fp);
	}
	else
	{


		printf("Enter Filename: ");
		scanf("%s", &fileName);
		getchar();

		FILE* fp = fopen(fileName, "r");
		if (fp == NULL)
		{
			printf("Can't open file!");
			return;
		}


		fscanf(fp, "%d", &tempLength);
		fgetc(fp);
		if (!reallocateMemory(&list->itemList, list->length + tempLength)) {
			printf("Failed to reallocate memory!");
			return;
		}


		i = list->length;
		list->length = list->length + tempLength;
		for (i; i < list->length; i++)
		{
			fgets(trashTemp, 5, fp);
			trashTemp[strlen(trashTemp) - 1] = '\0';
			fgets(list->itemList[i].productName, MAXNAME, fp);
			list->itemList[i].productName[strlen(list->itemList[i].productName) - 1] = '\0';
			fscanf(fp, "%f\n", &list->itemList[i].amount);
			fgets(list->itemList[i].unit, MAXNAME, fp);
			list->itemList[i].unit[strlen(list->itemList[i].unit) - 1] = '\0';

		}

		fclose(fp);
	}



}
//Kollar om talet  är negativt�
bool noNegativeNumbersAllowed(float number) {
	if (number < 0)
	{
		puts("No negative numbers allowed! Try again: ");
		return false;
	}
	return true;


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



