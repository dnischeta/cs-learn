#include <stdio.h>

int main() {
    int n = 1, upper;

    printf("Upper limit: ");
    scanf("%i", &upper);

    while (n < upper) {
        printf("%i\n", n);
        n++;
    }

    return 0;
}