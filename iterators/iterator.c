#include <stdlib.h>
#include <stdio.h>

#include "iterator.h"

typedef struct Iterator {
    void *buffer;
    int length;
    int current;
    int el_size;
} Iterator;

Iterator *create_iterator(void *buffer, int length, int el_size) {
    Iterator *iter = (Iterator *)malloc(sizeof(Iterator));

    if (iter == NULL) {
        perror("Failed to allocate iterator: ");
        exit(1);
    }

    iter->buffer = buffer;
    iter->current = 0;
    iter->length = length;
    iter->el_size=el_size;

    return iter;
}

char is_done(Iterator *iter) {
    return iter->current >= iter->length;
}

void next(Iterator *iter) {
    if (!is_done(iter))
        iter->current++;
}

void first(Iterator *iter) {
    iter->current = 0;
}

void *current_item(Iterator *iter) {
    return iter->buffer+(iter->current * iter->el_size);
}
