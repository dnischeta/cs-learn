#include <stdio.h>
#include <limits.h>

int greatest_number(int*, int);

int main() {
    int nums[] = { -99, 0, 1, 2, 999};
    printf("%d\n", greatest_number(nums, 5));
}

int greatest_number(int *nums, int len) {
    int max = INT_MIN;

    for (int idx = 0; idx < len; idx++) {
        if (nums[idx] > max) {
            max = nums[idx];
        }
    }

    return max;
}