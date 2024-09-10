#include <stdio.h>
#include <string.h>
#include "../../../../lib/input.h"

#define MAX_LENGTH 50

char is_palindrome(char *);

int main() {
    char s[MAX_LENGTH];

    while (1) {
        ask_for_string(s, MAX_LENGTH, "Please type in a palindrome: ");

        if (is_palindrome(s)) {
            printf("%s is a palindrome!\n", s);
            break;
        } else {
            printf("That wasn't a palindrome!\n");
        }
    }

    return 0;
}

char is_palindrome(char *s) {
    int l = 0, r = strlen(s) - 1;

    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }

        l++;
        r--;
    }

    return 1;
}