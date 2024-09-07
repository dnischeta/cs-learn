#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define MAX_LENGTH 10

int len(char *s) {
    int l = 0;

    while (s[l++] != '\0')
    ;

    return l;
}

char are_equal(char *w1, char *w2) {
    if (len(w1) != len(w2)) {
        return 0;
    }

    int idx = 0;

    while (w1[idx] != '\0') {
        if (w1[idx] != w2[idx]) {
            return 0;
        }

        idx++;
    }

    return 1;
}

void get_word(char *word) {
    int idx = 0;
    char c;

    printf("Word: ");
    while ((c = getchar()) != '\n') {
        // *(word+idx) = c;
        word[idx] = c;
        idx++;
    }
    // *(word+idx+1) = '\0';
    word[idx+1] = '\0';
}

void print_word(char *word) {
    for (int idx = 0; *(word + idx) != '\0'; idx++) {
        printf("%c", *(word + idx));
    }
    printf("\n");
}

int main() {
    int repeat = 0;
    int unique = 0;
    char words[MAX_LENGTH][MAX_WORD_LENGTH];

    while (1) {
        get_word(words[unique]);

        for (int idx = 0; idx < unique; idx++) {
            if (are_equal(words[unique], words[idx])) {
                repeat = 1;
            }
        }
    
        if (repeat) {
            break;
        }

        unique++;
    }

    printf("You typed in %i different words.\n", unique);

    return 0;
}