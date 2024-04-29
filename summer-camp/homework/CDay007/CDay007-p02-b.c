#include<stdio.h>
#define MAX_LEN 128

int main(){
    char str[MAX_LEN];
    printf("Enter a message:");
    char *p=str;
    for(;;){
        char c = getchar();
        if(c!='\n'){
            if((65<=c&&c<=90)||(97<=c&&c<=122)){
                *p = c;
                p++;
            }
        }else{
            *p = '\0';
            break;
        }
    }
    p--;   //将p指针移动到末尾
    char* q = str;   //将q指针指向开头
    while(q!=p){     //移动比较p和q
        if(*q == *p){
            q++;
            p--;
        }else{
            break;
        }
    }
    if(p == q){
        printf("Palindrome.");
    }else{
        printf("Not a palindrome.");
    }
    return 0;    
}

/**
 he lived as a devil, eh?
 Madmam, I am Adam.
*/