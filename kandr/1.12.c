#include <stdio.h>

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

int main() {
    int state = OUTSIDE_WORD, c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == INSIDE_WORD)
                putchar('\n');

            state = OUTSIDE_WORD;
        } else {
            state = INSIDE_WORD;
            putchar(c);
        }
    }

}