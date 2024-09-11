#include <stdio.h>
#include <string.h>
#include "../../../../lib/input.h"

int main() {
    int len = 4;
    int max_len = 0;
    char arr[][50] = {"first", "second", "fourth", "eleventh"};
    char *longest_arr[4];
    int longest_len = 0;
    int len_arr[4];

    for (int idx = 0; idx < len; idx++) {
        len_arr[idx] = strlen(arr[idx]);

        if (len_arr[idx] > max_len) {
            max_len = len_arr[idx];
        }
    }

    for (int idx = 0; idx < len; idx++) {
        if (len_arr[idx] == max_len) {
            longest_arr[longest_len] = arr[idx];
            longest_len++;
        }
    }

    print_str_arr(longest_arr, longest_len);
    printf("\n");

    return 0;
}