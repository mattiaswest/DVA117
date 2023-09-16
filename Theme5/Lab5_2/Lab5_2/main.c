#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void){
    char input[SIZE];
    int spaceCounter = 0;
    char* pThirdWord = 0;

    printf("Enter a sentence: ");
    fgets(input, SIZE, stdin);
    input[strlen(input) - 1] = '\0';
    int l = strlen(input);

    for (int i = 0; i < l; i++){
        if (input[i] == ' ')
            spaceCounter++;
        if (spaceCounter == 2){
            pThirdWord = &input[i + 1];
            break;
        }
    }
    if (spaceCounter < 2)
        printf("The sentence is too short!\n");
    else
        printf("%s\n", pThirdWord);
    return 0;
}