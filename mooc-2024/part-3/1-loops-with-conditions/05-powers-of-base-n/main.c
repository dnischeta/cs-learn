#include <stdio.h>

int main() {
    int limit, base, n = 1;

    printf("Upper limit: ");
    scanf("%i", &limit);
    
    printf("Base: ");
    scanf("%i", &base);

    while (n <= limit) {
        printf("%i\n", n);
        n *= base;
    }
    
    return 0;
}