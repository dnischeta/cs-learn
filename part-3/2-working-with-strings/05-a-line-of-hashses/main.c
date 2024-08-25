#include <stdio.h>

int main() {
    int qty;

    printf("Width: ");
    scanf("%i", &qty);

    while (qty > 0) {
        qty--;
        printf("#");
    }

    printf("\n");

    return 0;
}