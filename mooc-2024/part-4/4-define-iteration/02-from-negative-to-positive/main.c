#include <stdio.h>

int main() {
    // Не использую unsigned, потому что первое сравнение -> false
    // (int) -4 < (uint) 4 ? -> приведем int к uint и потеряем знак
    int limit;

    printf("Please type in a positive integer: ");
    scanf("%i", &limit);

    for (int n = -limit; n <= limit; n++) {
        if (n == 0)
            continue;
        printf("%i\n", n);
    }

    return 0;
}