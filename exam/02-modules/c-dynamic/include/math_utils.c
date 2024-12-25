#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int parseFloat(float *num, char *command, char **rest) {
    errno = 0;
    *num = strtof(command, rest);

    if (errno == ERANGE) {
        printf("Operand is too big.\n");
        return 0;
    }

    if (*rest == command) {
        printf("Operand is not a number.\n");
        return 0;
    }

    return 1;
}