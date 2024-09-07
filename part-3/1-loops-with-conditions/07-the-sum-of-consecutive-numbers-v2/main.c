#include <stdio.h>
#include <string.h>

#define STR_MAX_LENGTH 1000

int main() {
    char text[STR_MAX_LENGTH];
    char *str_start = "The consecutive sum: ";
    int idx = strlen(str_start);

    strncpy(text, str_start, idx);

    int limit, n = 1, total = 0;

    printf("Limit: ");
    scanf("%i", &limit);

    while (total < limit) {
        total += n;

        if (n == 1) {
            text[idx++] = '1';
        } else {
            text[idx++] = ' ';
            text[idx++] = '+';
            text[idx++] = ' ';
            // Только 0 - 9
            // text[idx++] = '0' + n;
            idx += snprintf(text + idx, sizeof(text) - idx, "%d", n);

            /**
             * - перевести число в строку
             * - strcat для конкатенации
             */
        }

        n++;
    }

    text[idx] = '\0';

    printf("%s\n", text);

    return 0;
}