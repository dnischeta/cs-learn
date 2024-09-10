#include <stdio.h>

#define MAX_LENGTH 100

void get_word(char *word) {
    int idx = 0;
    char c;

    while ((c = getchar()) != '\n') {
        // *(word+idx) = c;
        word[idx] = c;
        idx++;
    }
    // *(word+idx+1) = '\0';
    word[idx+1] = '\0';
}

int main() {
    char word[MAX_LENGTH];

    printf("Please type in a string: ");
    get_word(word);

    for (int idx = 0; word[idx] != '\0'; idx++) {
        printf("%c\n", word[idx]);
        printf("*\n");
    }

    return 0;
}