/*

 - The first two lines contain information about the file.
 
 - The first line verifies that the file being read has been created
   by this program.
 
 - The second line has information about the number of roots.
   Number of roots as in number of conversation starters, like "Hey", "Hi", and "Hello".
   One more field in the second line is the maximum conversation length. This is needed
   for the conversation parameter in the insertion algorithm.
 
 - The algorithms in this file use recursion to write and read.
   Keep in mind that the relations are not stored; the strings are.
   Sentence by sentence insertion is also possible due to the versatility of the insertion algorithm.
   Sentence by sentence insertion would be counterproductive though as information about sentence parents
   is needed, which can only be provided by a full conversation.
 
 - For the sake of readability, the tree writing and reading functions have each been bifurcated into two functions
   performing similar tasks. The first function deals with one root. The second function uses the first function to 
   deal with all the trees. This could have been crammed into one function but the decrease in readability would have not
   been negligible.
 
 - These functions are merely algorithms that operate on the structure defined in gtree.h . They have nothing to do with 
   natural language processing. Those algorithms will be kept in nlp.c .


*/
#include "gtreefio.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//NOTE: This function will overwrite the file. 
void write_gheader(char *fname, int nr, int mcl){
    FILE *f=fopen(fname,"w");
    int vbytes[]=VBYTES;
    fprintf(f,"%d %d %d %d %d\n",vbytes[0],vbytes[1],vbytes[2],vbytes[3],vbytes[4]);
    fprintf(f,"%d %d\n",nr, mcl);
    fclose(f);
}

// appends a tree in form of strings.
void gtwrites(char *fname, struct node **ghead){
    FILE *f=fopen(fname,"a");
    struct qn **head; //will be used for tree traversal
    
}