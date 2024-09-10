#include <stdio.h>
#include "../../../../lib/input.h"

#define LENGTH 5

int main() {
    int arr[LENGTH] = {1,2,3,4,5};

    while (1) {
        int idx = ask_for_int("Index [0;4]: ");

        if (idx < 0 || idx >= LENGTH) {
            printf("Index %i is out of range [0;4]\n", idx);
            break;
        }

        arr[idx] = ask_for_int("New value: ");

        print_int_arr(arr, LENGTH);
        printf("\n");
    }

    return 0;
}