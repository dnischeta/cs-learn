#include <stdio.h>

#define MAX_LENGTH 10

void insert_to_sorted(int *, int, int);
void print_arr(int *, int);

int main() {
    int length = 0;
    int arr[MAX_LENGTH];
    int sorted_arr[MAX_LENGTH];
    int el;

    while (1) {
        if (length == MAX_LENGTH) {
            printf("List has reached max length. Exiting...\n");
            break;
        }

        printf("New item: ");
        scanf("%i", &el);

        if (el == 0) {
            printf("Bye!\n");
            break;
        }

        arr[length] = el;
        insert_to_sorted(sorted_arr, el, length);
        length++;

        printf("The list now: ");
        print_arr(arr, length);
        printf("\n");
        printf("The list in order: ");
        print_arr(sorted_arr, length);
        printf("\n");
    }

    return 0;
}

void insert_to_sorted(int *arr, int num, int len) {
    if (len == MAX_LENGTH) {
        return;
    }

    if (len == 0) {
        *arr = num;
        return;
    }

    int first_greater_idx = 0;
    int right_idx = len - 1;

    while (first_greater_idx <= right_idx && *(arr + first_greater_idx) <= num)
        first_greater_idx++;

    
    while (right_idx >= first_greater_idx) {
        *(arr + right_idx + 1) = *(arr + right_idx);
        right_idx--;
    }

    *(arr + first_greater_idx) = num;
}

void print_arr(int *arr, int len) {
    printf("[");
    for (int idx = 0; len > 0; len--, idx++) {
        printf("%i", *(arr+idx));

        if (len > 1) {
            printf(", ");
        }
    }
    printf("]");
}