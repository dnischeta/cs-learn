#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    char str[MAX_LENGTH];

    while (1) {
        printf("Please type in a string: ");
        scanf("%s", str); // Doesn't work for empty strins!

        if (str[0] == '\n') {
            break;
        }

        printf("%s\n", str);

        for (int i = 0; i < strlen(str); i++) {
            printf("-");
        }

        printf("\n");
    }    
    
    return 0;
} 