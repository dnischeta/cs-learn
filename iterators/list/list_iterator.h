#ifndef LIST_ITER_H
#define LIST_ITER_H

#include "list.h"

typedef struct ListIterator ListIterator;

ListIterator *create_iterator(List *);
char is_done(ListIterator *);
int next(ListIterator *);
void first(ListIterator *);
void *current_item(ListIterator *);

#endif // LIST_ITER_H