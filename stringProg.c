#include <stdio.h>
#define TXT 1024
#define WORD 30
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
    int boll=0;
    printf("Gematria Sequences: ");
    while(input[i] != '~'){
        int start=i;
        for(i; i<LEN_ARRAY; i++){
            if(input[i] == '\n' || input[i] == '\t' || input[i] == ' ' || input[i] == '~'){
                break;
            }
        }
        for(start; start<i; start++){
            for(int end=start; end<LEN_ARRAY; end++){
                if(input[start]<65 || (input[start]>90 && input[start]<97) || input[start] > 122){
                    continue;
                }
                if(input[end]<65 || (input[end]>90 && input[end]<97) || input[end] > 122){
                    continue;
                }
                if(input[end] == ' ' || input[end] == '\n' || input[end] == '\t'){
                        continue;
                    }
                sum= gimatria(start, end);
                if(sum > gim){
                    break;
                }
                if(sum == gim){
                    if(boll == 1){
                        printf("~");
                    }
                    if(boll == 0){
                        boll = 1;
                    }
                    for(int j=start; j<=end; j++){
                        printf("%c", input[j]);
                    }
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

char cal_atbash(int ch){
    char ans;
    if(ch>= 65 && ch<= 90){
        ans= 91- ch;
        ans+= 64;
    }
    else if(ch>= 97 && ch<= 122){
        ans= 123- ch;
        ans+= 96;
     }
    else{
        ans= ch;
    }
   return ans; 
} 

void atbash(int end, int src){
    int boll= 0;
    char word[end];
    int i=src;
    int pointer;
    printf("Atbash Sequences: ");
    for(int j=0; j<end; j++){
        word[j]= cal_atbash(input[j]);
    }
    while(input[i] != '~'){
        int start=i;
        for(i; i<LEN_ARRAY; i++){
            if(input[i] == '\n' || input[i] == '\t' || input[i] == ' ' || input[i] == '~'){
                break;
            }
        }
        for(start; start<i; start++){
            if(input[start] == word[0]){
                pointer= 1;
                for(int sub=start+1; sub<LEN_ARRAY; sub++){
                    if(input[sub] == ' ' || input[sub] == '\n' || input[sub] == '\t'){
                        continue;
                    }
                    if(input[sub] != word[pointer] || input[sub] == '~'){
                        break;
                    }
                    pointer++;
                    if(pointer == end){
                          if(boll == 1){
                                printf("~");
                            }
                            if(boll == 0){
                                boll = 1;
                            }
                        for(start; start<=sub; start++){
                            printf("%c" ,input[start]);
                        }
                        break;
                    }
                }
            }
            else if(input[start] == word[end-1]){
                    pointer= end-2;
                for(int sub=start+1; sub<i; sub++){
                    if(input[sub] == ' ' || input[sub] == '\n' || input[sub] == '\t'){
                        continue;
                    }
                    if(input[sub] != word[pointer]){
                        break;
                    }
                    pointer--;
                      if(pointer == -1){
                        if(boll == 1){
                            printf("~");
                        }
                        if(boll == 0){
                            boll = 1;
                        }
                        for(start; start<=sub; start++){
                            printf("%c" ,input[start]);
                        }
                        break;
                    }
                }
            }
            else if(input[start] == ' '){
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

void print(int src, int dest, int boll){
    if(boll == 1){
        printf("~");
    }
    for(int i=src; i<=dest; i++){
        printf("%c", input[i]);
    }
}

// void angram(int end, int src){
//     char word[end];
//     int asci_word[128];
//     int asci_str[128];
//     int i=src;
//     int boll= 0;
//     printf("Anagram Sequences: ");
//     for(int j=0; j<end; j++){
//         word[j]= input[j];
//     }
//     for(int j=0; j<128; j++){
//         asci_word[j]= 0;
//         asci_str[j]= 0;
//     }
//     for(int j=0; j<end; j++){
//         asci_word[word[j]]++;
//     }
//     while(input[i] != '~'){
//         int start=i;
//         for(i; i<LEN_ARRAY; i++){
//             if(input[i] == '\n' || input[i] == '\t' || input[i] == ' ' || input[i] == '~'){
//                 break;
//             }
//         }
//         for(start; start<LEN_ARRAY; start++){
//             for(int dest=start; dest<LEN_ARRAY; dest++){
//                 if(input[dest] == '\n' || input[dest] == '\t' || input[dest] == ' '){
//                     continue;
//                 }
//                 if(asci_word[input[dest] == 0]){
//                     for(int j=0; j<128; j++){
//                         if(asci_word[j] != asci_str[j]){
//                             for(int k=0; k<128; k++){
//                                 asci_str[k] = 0;
//                             }
//                             break;
//                         }
//                     }
//                     if(boll == 0){
//                         boll == 1;
//                     }
//                     print(start, dest-1, boll);
//                 }   
//                 else{
//                     if(asci_str[input[dest]] < asci_word[input[dest]]){
//                         asci_str[input[dest]]++;
//                     }
//                     else{
//                         for(int j=0; j<128; j++){
//                         if(asci_word[j] != asci_str[j]){
//                             for(int k=0; k<128; k++){
//                                 asci_str[k] = 0;
//                             }
//                             break;
//                         }
//                     }
//                     if(boll == 0){
//                         boll == 1;
//                     }
//                     print(start, dest-1, boll);
//                     }
//                 }
//             }
//         }
//         if(input[i] == '~'){
//             break;
//         }
//         i++;
//     }
// }

void angram(int end, int src){

}

void insert(){
    char c;
    int i=0;
    while ( i<(WORD+TXT) && input[i-1] != '~'){
        scanf("%c", &c);
        input[i]= c;
        i++;
    }
}


int main(){   
    // i=0;
    // while ( i<(WORD+TXT)){
    //     printf("%c", input[i]);
    //     i++;
    // }
    insert();
    int index= endOfWord();
    int gim= gimatria(0, index-1);
    sameGim(index+1 , gim);
    atbash(index, index+1);
    angram(index, index+1);
    return 0;
}
