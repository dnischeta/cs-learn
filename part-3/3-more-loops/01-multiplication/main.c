#include <stdio.h>

int main() {
    int num;

    printf("Please type in a number: ");
    scanf("%i", &num);

    for (int left = 1; left <= num; left++) {
        for (int right = 1; right <= num; right++) {
            printf("%i x %i = %i\n", left, right, left * right);
        }
    }
    
    return 0;
}