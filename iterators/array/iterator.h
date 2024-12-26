#ifndef ITER_H
#define ITER_H

typedef struct Iterator Iterator;

/**
 * TODO:
 *  - don't like to pass el_size as a third param
 */

Iterator *create_iterator(void *, int, int);
char is_done(Iterator *);
void next(Iterator *);
void first(Iterator *);
void *current_item(Iterator *);

#endif // ITER_H