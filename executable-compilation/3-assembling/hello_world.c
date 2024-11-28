#include <stdio.h>

// cc -c hello_world.c -o hello_world.o


static int addTwo() {
    return 2;
}

int main() {
    int k = addTwo();
    printf("Hello, world!\n");
    return 0;
}
