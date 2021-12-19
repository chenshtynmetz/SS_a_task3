#include <stdio.h>
#include "stringProg.h"

int main(){   
    insert();
    int index= endOfWord();
    int gim= gimatria(0, index-1);
    sameGim(index+1 , gim);
    atbash(index, index+1);
    angram(index, index+1);
    return 0;
}