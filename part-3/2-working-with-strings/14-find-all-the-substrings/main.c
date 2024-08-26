#include <stdio.h>
#include <string.h>

int main() {
    char word[30], letter;

    printf("Please type in a word: ");
    scanf("%s", word);

    printf("Please type in a character: ");
    scanf(" %c", &letter);

    for (int idx = 0; idx < strlen(word) - 2; idx++) {
        if (word[idx] == letter) {
            printf("%c%c%c\n", word[idx], word[idx+1], word[idx+2]);
        }
    }

    return 0;
}