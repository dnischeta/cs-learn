#include <stdio.h>

#define LENGTH 5

int main() {
    unsigned short idx = -1;
    int arr[LENGTH] = {1,2,3,4,5};

    while (1) {
        printf("Index: ");
        scanf("%hi", &idx);

        if (idx < 0 || idx >= LENGTH) {
            break;
        }

        printf("New value: ");
        scanf("%i", arr + idx);

        printf("[");
        for (idx = 0; idx < LENGTH; idx++) {
            printf("%i", arr[idx]);

            if (idx < LENGTH - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    return 0;
}