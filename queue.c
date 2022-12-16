/*

- This is a queue that will be used in the IO algorithms for tree traversal.

*/
#include "queue.h"
#include <stdlib.h>
/*Does no logging. Just checks for allocation failures.*/
void *xmalloc(size_t size){
    void *ret;
    if((ret=malloc(size))==NULL){
        perror("[allocation]");
        exit(EXIT_FAILURE);
    }
    return ret;
}
void enqueue(struct qn **head, char *str){
    struct qn *save_h=*head;
    *head=(struct qn*)xmalloc(sizeof(struct qn));
    (**head).data=str;
    (**head).next=save_h;
}
struct qn *dequeue(struct qn **queue){
    if(*queue==NULL)return NULL;
    struct qn *save_h=*queue;
    *queue=(**queue).next;
    return save_h;
}