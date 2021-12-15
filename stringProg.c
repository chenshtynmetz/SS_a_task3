#include <stdio.h>
#define TXT 2
#define WORD 5
#define LEN_ARRAY (TXT+WORD)

char input[LEN_ARRAY];
// char atbash[WORD];

int gimatria(int src, int dest){
    int sum=0;
    for(int i=src; i<=dest; i++){
        if(input[i]>= 65 && input[i] <= 90){
            int asci= input[i]- 64;
            sum+= asci;
        }
        else if(input[i]>= 97 && input[i] <= 122){
            int asci= input[i]- 96;
            sum+= asci;  
        }
    }
    return sum;
}

int endOfWord(){
    int end_word;
    for(int i= 0; i<(LEN_ARRAY); i++){
        if(input[i] == '\n' || input[i] == '\t' || input[i] == ' ' ){
            end_word= i;
            break;
        }
    }
    return end_word;
}

void sameGim(int src, int gim){
    int i=src;
    int sum=0;
    printf("Gematria Sequences: ")
    while(input[i] != '~'){
        int start=i;
        for(i; i<LEN_ARRAY; i++){
            if(input[i] == '\n' || input[i] == '\t' || input[i] == ' ' || input[i] == '~'){
                break;
            }
        }
        for(start; start<i; start++){
            for(int end=start; end<i; end++){
                sum= gimatria(start, end);
                if(sum > gim){
                    break;
                }
                if(sum == gim){
                    for(int j=start; j<=end; j++){
                        printf("%c", input[j]);
                    }
                    printf('~');
                    break;
                }
            }
        }
        if(input[i] == '~'){
            break;
        }
        i++;
    }
    printf("\n");
}

char cal_atbash(int char){
    char ans;
    if(char>= 65 && char<= 90){
        ans= 91- char;
        ans+= 64;
    }
    else if(char>= 97 && char<= 122){
        ans= 123- char;
        ans+= 96;
     }
    else{
        ans= char;
    }
   return ans; 
} 

void atbash(int end, int src){
    char word[end];
    int i=src;
    for(int j=0; j<end; j++){
        word[j]= cal_atbash(input[j]);
    }
    while(input[i] != '~'){
        int start=i;
        for(i; i<LEN_ARRAY; i++){
            if(input[i] == '\n' || input[i] == '\t' || input[i] == '~'){
                break;
            }
        }
        for(start; start<i; start++){
            if(input[start] == word[0]){
                pointer= 1;
                for(int sub=start+1; sub<i; sub++){
                    if(input[sub] == ' '){
                        continue;
                    }
                    if(input[sub] != word[pointer]){
                        break;
                    }
                    pointer++;
                    if(pointer == end){
                        for(start; start<=sub; start++){
                            printf(input[start]);
                        }
                        printf("~");
                        break;
                    }
                }
            }
            else if(input[start] == word[end-1]){
                    pointer= end-2;
                for(int sub=start+1; sub<i; sub++){
                    if(input[sub] == ' '){
                        continue;
                    }
                    if(input[sub] != word[pointer]){
                        break;
                    }
                    pointer--;
                      if(pointer == -1){
                        for(start; start<=sub; start++){
                            printf(input[start]);
                        }
                        printf("~");
                        break;
                    }
                }
            }
            else if(input[start] == " "){
                continue; //ask if need to print the space
            }
        }
        if(input[i] == '~'){
            break;
        }
        i++;
    }
    printf("\n");   
}


void main(){
    char c;
    int i=0;
    while ( i<(WORD+TXT)){
        scanf("%c", &c);
        input[i]= c;
        i++;
    }
    // i=0;
    // while ( i<(WORD+TXT)){
    //     printf("%c", input[i]);
    //     i++;
    // }
    int index= endOfWord();
    int gim= gimatria(0, index-1);
    sameGim(index+1 , gim);
    atbash(index, index+1);

}
