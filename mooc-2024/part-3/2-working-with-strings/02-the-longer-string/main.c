#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Please type in a string 1: ");
    scanf("%s", str1);

    printf("Please type in a string 2: ");
    scanf("%s", str2);

    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    if (str1_len == str2_len) {
        printf("The strings are equally long\n");
    } else if (str1_len > str2_len) {
        printf("%s is longer\n", str1);
    } else {
        printf("%s is longer\n", str2);
    }

    return 0;
}