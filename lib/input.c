#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "input.h"

#define SMALL_BUF_SIZE 1024

char buf[SMALL_BUF_SIZE];

int ask_for_int(char *msg) {
    int success = 0;
    int a = 0;

    do {
        printf("%s", msg);

        if (!fgets(buf, SMALL_BUF_SIZE, stdin)) {
            // TODO: implement exception?
        }

        char *endptr;
        errno = 0; // Reset error

        a = strtol(buf, &endptr, 10);

        if (errno == ERANGE) {
            printf("This number is too large or too small\n");
            success = 0;
        } else if (buf == endptr) { // No character was read
            success = 0;
        } else if (*endptr && *endptr != '\n') {
            success = 0;
        } else {
            success = 1;
        }
    }
    while (!success);

    return a;
}

void ask_for_string(char *str, int len, char *msg) {
    printf("%s", msg);
    if (fgets(str, len, stdin)) {
        str[strcspn(str, "\n")] = 0;
    } else {
        // TODO: implement?
    }
}

void print_int_arr(int arr[], int length) {
    printf("[");
    for (int idx = 0; idx < length; idx++) {
        printf("%i", arr[idx]);

        if (idx < length - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void print_str_arr(char *arr[], int length) {
    printf("[");
    for (int idx = 0; idx < length; idx++) {
        printf("%s", arr[idx]);

        if (idx < length - 1) {
            printf(", ");
        }
    }
    printf("]");
}