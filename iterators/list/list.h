#ifndef H_LIST
#define H_LIST

typedef struct List List;

List *create_list(void *buf, int cap, int len, int el_size);

int append(List *, void *);
void *pop(List *);
int len(List *);
void *at(List *, int);

#endif  // H_LIST