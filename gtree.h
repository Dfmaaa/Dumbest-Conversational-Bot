#ifndef GTREE_H
#define GTREE_H

#define CHILD_MAX 7000
#include <stdio.h>
struct node{
    char *data; //The sentence
    int depth; //depth of sentence in a conversation
    struct node *children[CHILD_MAX]; //Hash table that stores child pointers
};
void fwnull(struct node **, int);
void *xmalloc(size_t);
void insert(struct node***, char **, int, int);

#endif