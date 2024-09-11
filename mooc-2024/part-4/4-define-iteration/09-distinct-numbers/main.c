#include <stdio.h>
#include <stdlib.h>
#include "../../../../lib/input.h"

int to_distinct(int *, int, int *);
int compare(const void *, const void *);

int main() {
    int arr[] = {2,3,4,1,2, -100,3,4};
    int distinct_arr[10];

    int len_distinct = to_distinct(arr, 7, distinct_arr);

    qsort(distinct_arr, len_distinct, sizeof(arr[0]), compare);

    print_int_arr(distinct_arr, len_distinct);
    printf("\n");

    return 0;
}

int to_distinct(int *arr, int len, int *distinct_arr) {
    int len_distinct = 0;

    for (int idx = 0; idx < len; idx++) {
        int idx2;
        for (idx2 = 0; idx2 < len_distinct; idx2++) {
            if (arr[idx] == distinct_arr[idx2]) {
                break;
            }
        }

        if (idx2 == len_distinct) {
            len_distinct++;
            distinct_arr[idx2] = arr[idx];
        }
    }

    return  len_distinct;
}

int compare(const void * x1, const void * x2)
{
  return ( *(int*)x1 - *(int*)x2 );
}
