#include <stdio.h>

int main() {
    int n;

    printf("Are you ready?\n");
    printf("Please type in a number: ");
    scanf("%i", &n);

    while (n > 0) {
        printf("%i\n", n);
        n--;
    }

    return 0;
}