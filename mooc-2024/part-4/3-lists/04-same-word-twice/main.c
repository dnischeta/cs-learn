#include <stdio.h>
#include <string.h>
#include "../../../../lib/input.h"

#define MAX_WORD_LENGTH 20
#define MAX_LENGTH 10

char are_equal(char *w1, char *w2) {
    if (strlen(w1) != strlen(w2)) {
        return 0;
    }

    int idx = 0;

    while (w1[idx]) {
        if (w1[idx] != w2[idx]) {
            return 0;
        }

        idx++;
    }

    return 1;
}

int main() {
    int repeat = 0;
    int unique = 0;
    char words[MAX_LENGTH][MAX_WORD_LENGTH];

    while (1) {
        ask_for_string(words[unique], MAX_WORD_LENGTH, "Word: ");

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