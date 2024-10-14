#include <stdio.h>
#include <string.h>
#include "naive.h"

NaiveKVs map;

NaiveKVs *create_naive_hash_map() {
    for (int idx = 0; idx < MAP_CAPACITY; idx++) {
        map.data[idx].key = NULL;
        map.data[idx].value = 0.0;
    }

    return &map;
}

void add_naive_hash_map(NaiveKVs *map, char *key, float value) {
    int index = strlen(key);
    map->data[index].key = key;
    map->data[index].value = value;
}

float get_naive_hash_map(NaiveKVs *map, char *key) {
    int index = strlen(key);
    if (strcmp(map->data[index].key, key) == 0) {
        return map->data[index].value;
    }
    
    return 0;
}

void print_naive_hash_map(NaiveKVs *map) {
    for (int idx = 0; idx < MAP_CAPACITY; idx++) {
        if (map->data[idx].key != NULL) {
            printf("| %s : %.2f |\n", map->data[idx].key, map->data[idx].value);
        }
    }
}