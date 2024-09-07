#include <stdio.h>

int range_of_a_list(int *arr, int length) {
    int min = *arr, max = *arr, idx = 1;

    while (idx < length) {
        if (arr[idx] < min)
            min = arr[idx];
        if (arr[idx] > max)
            max = arr[idx];
        idx++;
    }

    return max - min;
}

int main() {
    int arr[] = {-11,2,3,4,5};
    printf("The range of the list is %i\n", range_of_a_list(arr, 5));
}