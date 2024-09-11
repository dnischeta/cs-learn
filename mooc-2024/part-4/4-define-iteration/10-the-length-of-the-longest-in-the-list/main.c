#include <stdio.h>
#include <string.h>

int main() {
    int len = 4;
    int max_len = 0;
    char arr[][50] = {"first", "second", "fourth", "eleventh"};
    
    for (int idx = 0; idx < len; idx++) {
        if (strlen(arr[idx]) > max_len) {
            max_len = strlen(arr[idx]);
        }
    }

    printf("The maximum length: %d\n", max_len);

    return 0;
}