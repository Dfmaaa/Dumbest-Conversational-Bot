/*

- This is a hash function for strings. The function sci(char *, int) takes 
  a string and the biggest integer the function can return. The second parameter is only
  needed if initial output is bigger than it. If that is the case, the mathematical function modulus
  will be used to make the initual output smaller than max. This does reduce the chances of the final output
  being distinctive but is important as it prevents segmentation faults.

*/
#include "hash.h"
#include <string.h>
int sci(char *s, int max){
    int len;
    if((len=strlen(s))<2){
        if(len==0)return -1;
        return ((int)s[0])+MAGICAL_K;
    }
    int firstb=(int)s[0];
    int lastb=(int)s[len];
    int end=len;
    int start=0;
    int output[len];
    while(end>start){
        output[start]=(((int)s[start])&firstb)|MAGICAL_K;
        output[end]=(((int)s[end])&lastb)|MAGICAL_K;
        start++;
        end--;
    }
    int ret=0;
    int counter=0;
    while(counter<len){
        ret+=output[counter];
        counter++;
    }
    if(ret>max){
        return ret%max;
    }
    return ret;
}