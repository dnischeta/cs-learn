#include <stdio.h>

#define MAX_LENGTH 1000

int main() {
    int qty;
    char input[MAX_LENGTH];

    printf("Please type in a string: ");
    scanf("%s", input);

    printf("Please type in an amount: ");
    scanf("%i", &qty);

    for (int i = 1; i <= qty; i++) {
        printf("%s", input);
    }

    printf("\n");
    
    return 0;
}