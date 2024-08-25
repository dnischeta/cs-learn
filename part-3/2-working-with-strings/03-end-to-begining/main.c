#include <stdio.h>

#define MAX_LENGTH 1000

int main() {
    char str[MAX_LENGTH];
    printf("Please type in a string: ");
    scanf("%s", str);

    // May be replaced with strlen from string.h
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    while (len > 0) {
        printf("%c\n", str[len-1]);
        len--;
    }

    return 0;
}