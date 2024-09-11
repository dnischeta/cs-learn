#include <stdio.h>
#include <string.h>
#include "../../../../lib/input.h"

int main() {
    int len = 4;
    int min_len = 999;
    char *min_str = NULL;
    char arr[][50] = {"the", "second", "fourth", "eleventh"};
    
    for (int idx = 0; idx < len; idx++) {
        if (strlen(arr[idx]) < min_len) {
            min_len = strlen(arr[idx]);
            min_str = arr[idx];
        }
    }

    printf("The minimum length: %d\n", min_len);
    printf("%s\n", min_str);

    return 0;
}