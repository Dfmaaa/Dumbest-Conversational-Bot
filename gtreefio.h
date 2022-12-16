#ifndef GTREEFIO_H
#define GTREEFIO_H

#include "gtree.h"
#define END_TREE "FIQJFIJ0P9SDFPAI"
#define VBYTES {502,911,627,503,729} //Bytes to be used for verification.
void write_gheader(char *,int , int);
struct node **gtreads(char *);
void gtwrites(char *,struct node **);
struct node ***gtread(char *);
void gtwrite(struct node ***);

#endif