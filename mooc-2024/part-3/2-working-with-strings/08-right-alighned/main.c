#include <stdio.h>

#define MAX_LENGTH 20

int main() {
    char string[MAX_LENGTH];

    printf("Please type in a string: ");
    scanf("%s", string);

    int len = 0;
    int starQty = MAX_LENGTH;

    while (string[len] != '\0') {
        len++;
    }

    starQty = MAX_LENGTH - len;

    while (starQty > 0) {
        starQty--;
        printf("*");
    }

    printf("%s\n", string);

    return 0;
}