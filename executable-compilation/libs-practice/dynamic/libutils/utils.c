#include "utils.h"
#include <stdio.h>

void hello(void) {
    printf("Hello from shared library!\n");
}

int add(int a, int b) {
    return a + b;
}
