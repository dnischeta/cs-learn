#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    void *data;
    int len;
} List;

List *create_list(int len) {
    List *l = (List *)malloc(sizeof(List));

    if (l == NULL) {
        perror("Failed to allocate list: ");
        exit(1);
    }

    void *data = malloc(len);

    if (data == NULL) {
        perror("Failed to allocate list data: ");
        exit(1);
    }

    l->len = len;
    l->data = data;

    return l;
}

typedef struct Iterator {
    List *list;
    int current;
} Iterator;

Iterator *create_iterator(List *list) {
    Iterator *iter = (Iterator *)malloc(sizeof(Iterator));

    if (iter == NULL) {
        perror("Failed to allocate iterator: ");
        exit(1);
    }

    iter->list = list;
    iter->current = 0;

    return iter;
}

char is_done(Iterator *iter) {
    return iter->current >= iter->list->len;
}

void next(Iterator *iter) {
    if (!is_done(iter)) {
        iter->current++;
    }
}

void first(Iterator *iter) {
    iter->current = 0;
}

void *current_item(Iterator *iter) {
    return iter->list+iter->current;
}

void print_list(Iterator *iter) {
    first(iter);
    printf("[");
    while (!is_done(iter)) {
        printf("%d", *(int *)current_item(iter));
        next(iter);
        if (!is_done(iter))
            printf(", ");
    }
    printf("]\n");
}

int main() {
    List *nums_list = create_list(5);
    Iterator *nums_list_iter = create_iterator(nums_list);

    int current_el = 1;
    
    for (; !is_done(nums_list_iter); next(nums_list_iter)) {
        *(int *)current_item(nums_list_iter) = current_el++;
    }

    print_list(nums_list_iter);    
}
