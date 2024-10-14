#include <stdio.h>
#include <stdlib.h>
#include "../../../../hash-table/naive.h"

int main() {
    char keys[10][10];
    float values[10];
    int idx = 0;
    NaiveKVs *map = create_naive_hash_map();
    char *line;
    size_t line_len;
    FILE *fp;
    fp = fopen("fruits.csv", "r");

    while((line = fgetln(fp, &line_len)) != NULL) {
        int key_done = 0;
        int idx_str = 0;
        for (; idx_str < line_len-1; idx_str++) {
            if (line[idx_str] == ';') {
                key_done = 1;
                keys[idx][idx_str-1] = 0;
                idx_str++;
                break;
            }
            if (!key_done) {
                keys[idx][idx_str] = line[idx_str];
            }
        }
        char *end_ptr;
        values[idx] = strtof(line + idx_str, &end_ptr);
        idx++;
    }

    for (int idx2 = 0; idx2 < idx; idx2++) {
        add_naive_hash_map(map, keys[idx2], values[idx2]);
    }

    for (int idx3 = 0; idx3 < idx; idx3++) {
        printf("%s: %f\n", keys[idx3], get_naive_hash_map(map, keys[idx3]));
    }
}