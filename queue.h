#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
struct qn{
    char *data;
    struct qn *next;
};
void *xmalloc(size_t);
void enqueue(struct qn **, char *);
struct qn *dequeue(struct qn**);

#endif