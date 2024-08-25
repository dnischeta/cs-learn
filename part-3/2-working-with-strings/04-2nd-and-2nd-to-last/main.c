#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char string[MAX_LENGTH];

    printf("Please type in a string: ");
    scanf("%s", string);

    int len = strlen(string);

    if (string[1] == string[len-2]) {
        printf("The second and the second to last characters are %c\n", string[1]);
    } else {
        printf("The second and the second to last characters are different\n");
    }
}