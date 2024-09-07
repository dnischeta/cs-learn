#include <stdio.h>

int main() {
    int arr[] = {1,2,3,4,5,4,3,2,1};


    for (int idx = 0; idx < 9; idx++) {
        for (int idx2 = 1; idx2 <= arr[idx]; idx2++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}