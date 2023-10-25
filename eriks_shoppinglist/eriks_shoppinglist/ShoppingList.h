#include <stdbool.h>
#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H
/*Här lägger du eventuella makrodefinitioner*/
#define MAXNAME 20
// Struct definitions

/*Deluppgift 3 - definiera dina strukter här.           *
 *Det är viktigt att du använder de namn som anges i    *
 *uppgiftsspecifikationen, har du inte gjort det kommer *
 *resten av kodskelettet inte att kompilera.            *
 *När du definierat strukternakommer eventuella         *
 *varningar att försvinna och du ska kunna kompilera    *
 *och köra programmet, ingenting kommer dock att hända  *
 *när du gör val i menyn.                               */
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
