#include <stdio.h>
#include "../../../../lib/input.h"

int main() {
    int n = ask_for_int("Please, type in an integer number: ");

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i - 1);
        } else if (i < n) {
            printf("%d\n", i + 1);
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}