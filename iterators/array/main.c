#include <stdio.h>

#include "iterator.h"

void print_arr(Iterator *iter) {
    printf("[");

    while (1) {
        printf("%d", *(int *)current_item(iter));
        next(iter);

        if (is_done(iter))
            break;

        printf(", ");
    }
    printf("]\n");
}

int main() {
    int nums[] = {1,2,3,4,5};
    Iterator *iter = create_iterator(nums, 5, sizeof(int));
    print_arr(iter);
}