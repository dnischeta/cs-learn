#include <stdio.h>
#include "../../../../lib/input.h"

int main()
{
    int len = 5;
    int original[] = {1,2,3,4,5};
    int even[len];
    int idx_even = 0;

    for (int idx = 0; idx < len; idx++) {
        if (original[idx] % 2 == 0) {
            even[idx_even++] = original[idx];
        }
    }

    printf("Original: ");
    print_int_arr(original, len);
    printf("\n");
    printf("Even: ");
    print_int_arr(even, idx_even);
    printf("\n");

    return 0;
}