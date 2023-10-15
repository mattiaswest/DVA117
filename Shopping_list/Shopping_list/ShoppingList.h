#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H
/*Här lägger du eventuella makrodefinitioner*/
#define MAX 50


// Struct definitions
struct GroceryItem {
	char productName[MAX];
	float amount;
	char unit[MAX];
};

struct ShoppingList {
	struct GroceryItem itemList[5];
	int length;
};



 // Function declarations

int isPositive(float number);
int inList(int entry, struct ShoppingList* list);
void addItem(struct ShoppingList* list);
void printList(struct ShoppingList* list);
void editItem(struct ShoppingList* list);
void removeItem(struct ShoppingList* list);
void saveList(struct ShoppingList* list); //implementeras i laboration 7
void loadList(struct ShoppingList* list); //implementeras i laboration 7

#endif
