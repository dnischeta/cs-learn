#include <stdio.h>
#include <string.h>

int main() {
    char word[30];
    int len;

    printf("Please type in a string: ");
    scanf("%s", word);
    
    len = strlen(word);

    for (int r = 0; r < len; r++) {
        for (int c = 0; c <= r; c++) {
            printf("%c", word[c]);
        }

        printf("\n");
    }

    return 0;
}