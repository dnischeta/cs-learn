#include <stdio.h>
#include "../../../../lib/input.h"

int main() {
    int limit = ask_for_int("Please type in a positive integer: ");

    for (int n = -limit; n <= limit; n++) {
        if (n == 0)
            continue;
        printf("%i\n", n);
    }

    return 0;
}