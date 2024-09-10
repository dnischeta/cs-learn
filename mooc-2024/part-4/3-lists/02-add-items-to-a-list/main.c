#include <stdio.h>
#include "../../../../lib/input.h"

#define MAX_LENGTH 10

int main() {
    int arr[MAX_LENGTH];
    short idx = 0;

    int length = ask_for_int("How many items: ");

    if (length > MAX_LENGTH || length < 0) {
        printf("Length is out of range\n");
        return 1;
    }

    if (length == 0) {
        printf("[]\n");
        return 0;
    }

    char str_ptr[10];

    for (idx = 0; idx < length; idx++) {
        sprintf(str_ptr, "Item %i: ", idx);
        arr[idx] = ask_for_int(str_ptr);
    }

    print_int_arr(arr, length);
    printf("\n");

    return 0;
}