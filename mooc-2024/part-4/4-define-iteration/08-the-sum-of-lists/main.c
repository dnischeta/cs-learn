#include <stdio.h>
#include "../../../../lib/input.h"

int main() {
    const int len = 5;
    int l1[] = {1,2,3,4,5};
    int l2[] = {1,2,3,4,5};
    int res[len];

    for (int idx = 0; idx < len; idx++) {
        res[idx] = l1[idx] + l2[idx];
    }

    print_int_arr(res, len);
    printf("\n");
    
    return 0;
}