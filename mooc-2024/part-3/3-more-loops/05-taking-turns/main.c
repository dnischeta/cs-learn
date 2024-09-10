#include <stdio.h>
#include "../../../../lib/input.h"

int main() {
    int i = 1;
    int n = ask_for_int("Please, type in an integer number: ");

    for (; i < n; i++, n--) {
        printf("%d\n", i);
        printf("%d\n", n);
    }

    if (i == n) {
        printf("%d\n", n);
    }

    return 0;
}
