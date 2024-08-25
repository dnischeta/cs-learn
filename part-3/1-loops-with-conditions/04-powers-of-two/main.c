#include <stdio.h>

int main() {
    int n = 1, limit;

    printf("Upper limit: ");
    scanf("%i", &limit);

    while (n <= limit) {
        printf("%i\n", n);
        n *= 2;
    }
    
    return 0;
}