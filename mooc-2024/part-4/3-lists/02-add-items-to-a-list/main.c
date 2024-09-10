#include <stdio.h>

#define MAX_LENGTH 10

int main() {
    int arr[MAX_LENGTH];
    unsigned short idx = 0;
    unsigned short length = 0;

    printf("How many items: ");
    scanf("%hu", &length);

    if (length > MAX_LENGTH || length < 0) {
        return 1;
    }

    if (length == 0) {
        printf("[]\n");
        return 0;
    }

    for (idx = 0; idx < length; idx++) {
        printf("Item %i: ", idx + 1);
        scanf("%i", arr + idx);
    }

    printf("[");
    for (idx = 0; idx < length; idx++) {
        printf("%i", arr[idx]);

        if (idx < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}