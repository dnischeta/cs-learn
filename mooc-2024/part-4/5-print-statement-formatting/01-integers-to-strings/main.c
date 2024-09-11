#include <stdio.h>
#include "../../../../lib/input.h"

int main() {
    float arr[] = {1.234, 0.3333, 0.11111, 3.446};
    char arr_str[4][10];
    char *arr_ptr[4];

    for (int idx = 0; idx < 4; idx++) {
        sprintf(arr_str[idx], "'%.2f'", arr[idx]);
        arr_ptr[idx] = arr_str[idx];
    }

    print_str_arr(arr_ptr, 4);
    printf("\n");
    
    return 0;
}