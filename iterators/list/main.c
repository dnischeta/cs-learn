#include <stdio.h>

#include "list.h"
#include "list_iterator.h"

int main() {
    int nums_arr[] = {1,2,3,4,5};
    List *l = create_list(nums_arr, 5 * sizeof(int), 5, sizeof(int));

    ListIterator *iter = create_iterator(l);

    while (!is_done(iter)) {
        printf("%d\n", *(int *)current_item(iter));
        next(iter);
    }
}