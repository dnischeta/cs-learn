#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int max = INT_MIN, num;
    char *line;
    size_t line_len;
    FILE *fp;
    fp = fopen("numbers.txt", "r");

    while ((line = fgetln(fp, &line_len)) != NULL) {
        num = strtol(line, NULL, 10);
        max = num > max ? num : max;
    }

    printf("Maximum number is %i\n", max);

    return 0;
}
