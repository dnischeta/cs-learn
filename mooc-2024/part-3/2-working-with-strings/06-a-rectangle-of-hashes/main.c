#include <stdio.h>

int main() {
    int w, h;

    printf("Width: ");
    scanf("%i", &w);
    
    printf("Height: ");
    scanf("%i", &h);

    while (h > 0) {
        h--;
        for (int i = 0; i < w; i++) {
            printf("#");
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}