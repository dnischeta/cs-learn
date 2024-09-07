#include <stdio.h>

float mean(int *arr, int len) {
    int sum = 0;

    for (int idx = 0; idx < len; idx++) {
        sum += *(arr + idx);
    }
    

    return sum / (len - 1);
}

int main() {
    int arr[] = {1,2,3,4,5};

    printf("Mean is %.1f\n", mean(arr, 5));
    
    return 0;
}