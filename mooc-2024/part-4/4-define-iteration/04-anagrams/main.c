#include <stdio.h>
#include <string.h>
#include "../../../../lib/input.h"

#define MAX_LENGTH 50

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    int len, found_idx_qty = 0;
    char not_anagrams[] = "Strings are not anagrams.";

    ask_for_string(s1, MAX_LENGTH, "Please, type in 1st word: ");
    ask_for_string(s2, MAX_LENGTH, "Please, type in 2nd word: ");

    if ((len = strlen(s1)) != strlen(s2)) {
        printf("%s\n", not_anagrams);
        return 0;
    }

    for (int idx = 0; idx < len; idx++) {
        char found = 0;
        for (int idx2 = 0; idx2 < len; idx2++) {
            if (s1[idx] == s2[idx2]) {
                s2[idx2] = 0;
                found = 1;
                break;
            }
        }

        if (!found) {
            break;
        }

        found_idx_qty++;
    }

    if (found_idx_qty < len) {
        printf("%s\n", not_anagrams, found_idx_qty);
        return 0;
    }

    printf("Strings are anagrams.\n");

    return 0;
}