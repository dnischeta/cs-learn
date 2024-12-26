#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct List {
    void *buf;
    int cap;
    int el_size;
    int len;
} List;

List *create_list(void *buf, int cap, int len, int el_size) {
    List *l = (List *)malloc(sizeof(List));

    if (l == NULL) {
        perror("Failed to allocate list: ");
        exit(1);
    }

    l->buf = buf;
    l->cap = cap;
    l->el_size = el_size;
    l->len = len;

    return l;
}

int append(List *l, void *el) {
    if ((l->len + 1) * l->el_size > l->cap) {
        return -1;
    }

    char* dest = (char*)l->buf + (l->len * l->el_size);
    // Why not `memset`?
    memcpy(dest, el, l->el_size);
    l->len++;

    return 0;
}

int len(List *l) {
    return l->len;
}

void *at(List *l, int idx) {
    if (idx >= l->len)
        return NULL;

    return (char *)l->buf + idx * l->el_size;
}

void *pop(List *l) {
    void *last = at(l, l->len - 1);
    l->len--;
    return last;
}
