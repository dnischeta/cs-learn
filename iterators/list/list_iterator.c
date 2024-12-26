#include <stdlib.h>

#include "list.h"
#include "list_iterator.h"

typedef struct ListIterator {
    List *list;
    int current;
} ListIterator;

ListIterator *create_iterator(List *l) {
    ListIterator *iter = (ListIterator *)malloc(sizeof(ListIterator));
    iter->list = l;
    iter->current = 0;
    return iter;
}

char is_done(ListIterator *iter) {
    return iter->current >= len(iter->list);
}

int next(ListIterator *iter) {
    if (is_done(iter))
        return -1;

    iter->current++;
    return 0;
}

void first(ListIterator *iter) {
    iter->current = 0;
}

void *current_item(ListIterator *iter) {
    return at(iter->list, iter->current);
}