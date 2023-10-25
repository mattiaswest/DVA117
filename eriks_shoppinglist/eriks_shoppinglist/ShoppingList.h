#include <stdbool.h>
#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H
/*H�r l�gger du eventuella makrodefinitioner*/
#define MAXNAME 20
// Struct definitions

/*Deluppgift 3 - definiera dina strukter h�r.           *
 *Det �r viktigt att du anv�nder de namn som anges i    *
 *uppgiftsspecifikationen, har du inte gjort det kommer *
 *resten av kodskelettet inte att kompilera.            *
 *N�r du definierat strukternakommer eventuella         *
 *varningar att f�rsvinna och du ska kunna kompilera    *
 *och k�ra programmet, ingenting kommer dock att h�nda  *
 *n�r du g�r val i menyn.                               */
struct GroceryItem {
	char productName[MAXNAME];
	float amount;
	char unit[MAXNAME];


};

struct ShoppingList {
	struct GroceryItem* itemList;
	int length;






};


// Function declarations

void addItem(struct ShoppingList* list);
void printList(struct ShoppingList* list);
void editItem(struct ShoppingList* list);
void removeItem(struct ShoppingList* list);
void saveList(struct ShoppingList* list); //implementeras i laboration 7
void loadList(struct ShoppingList* list); //implementeras i laboration 7
bool noNegativeNumbersAllowed(float number);
int reallocateMemory(struct GroceryItem** oldMemory, int newNemory);

#endif
