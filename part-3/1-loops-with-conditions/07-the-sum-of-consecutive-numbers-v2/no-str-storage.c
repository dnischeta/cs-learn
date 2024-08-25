#include <stdio.h>

#define STR_MAX_LENGTH 1000

int main() {
    int limit, n = 1, total = 0;

    printf("Limit: ");
    scanf("%i", &limit);

    while (total < limit) {
        total += n;

        if (n == 1) {
            printf("The consecutive sum: 1");
        } else {
            printf(" + %i", n);
        }

        n++;
    }

    printf(" = %i\n", total);

    return 0;
}