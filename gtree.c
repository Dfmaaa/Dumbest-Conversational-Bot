#include <stdlib.h>
#include "gtree.h"
#include "hash.h"
void fwnull(struct node **arr, int _s){
    for(int counter=0;counter<_s;counter++){
        arr[counter]=NULL;
    }
}
/*Does no logging. Just checks for allocation failures.*/
void *xmalloc(size_t size){
    void *ret;
    if((ret=malloc(size))==NULL){
        perror("[allocation]");
        exit(EXIT_FAILURE);
    }
    return ret;
}
/*

 - This algorithm uses a hash function for deciding which node to traverse.
 
 - CHILD_MAX, a macro which affects the size of the node structure can, and should be 
   changed because each node takes up at least(at least because structure packing is not being used) 14006 bytes.
   That's because the macro CHILD_MAX is 7000 as of now. This is a precaution because a conversation can have many branches.
 
 - Each node has a depth that can be used for debugging purposes.

*/
void insert(struct node ***root,char **conversation, int c_len, int r_len){
    int sc=0;
    int roothash=sci(conversation[0],r_len);
    struct node **narr;
    if(*root[roothash]==NULL){
        *root[roothash]=(struct node*)xmalloc(sizeof(struct node));
        (*(*(root+roothash)))->data=conversation[0];
        (*(*(root+roothash)))->depth=0;
        fwnull((*(*(root+roothash)))->children,CHILD_MAX);
    }
    sc++;
    narr=(*(*(root+roothash)))->children;
    struct node *selected;
    // This while loop traverses to one of the leaves.
    while((selected=narr[sci(conversation[sc],CHILD_MAX)])!=NULL){
        narr=selected->children;
        sc++;
    }
    /* 
    
    - sc is where we have to start from because there's no branch for it.
    
    - This works for new conversations too because even the first iteration wont happen. 
    
    */
    while(sc<c_len){
        narr[sci(conversation[sc],CHILD_MAX)]=(struct node*)xmalloc(sizeof(struct node));
        narr[sci(conversation[sc],CHILD_MAX)]->data=conversation[sc];
        narr[sci(conversation[sc],CHILD_MAX)]->depth=sc;
        fwnull(narr[sci(conversation[sc],CHILD_MAX)]->children,CHILD_MAX);
        narr=narr[sci(conversation[sc],CHILD_MAX)]->children;
        sc++;
    }
}