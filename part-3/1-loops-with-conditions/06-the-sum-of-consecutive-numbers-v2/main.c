#include <stdio.h>

int main() {
    int limit, n = 1, total = 0;

    printf("Limit: ");
    scanf("%i", &limit);

    while (total < limit) {
        total += n;
        n++;
    }

    printf("%i\n", total);

    return 0;
}