#include<stdio.h>
#define MAX_LEN 128
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

int main(){
    char str[MAX_LEN];
    printf("Enter a message:");
    int i =0;
    for(;;){
        char c = getchar();
        if(c!='\n'){
            if((65<=c&&c<=90)||(97<=c&&c<=122)){
                str[i] = c;
                i++;
            }
        }else{
            str[i] = '\0';
            break;
        }
    }
    i--;
    int front = 0;
    for(;;){
        if(front!=i){
            if(str[front] == str[i]){
                front++;
                i--;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    if(front == i){
        printf("Palindrome.");
    }else{
        printf("Not a palindrome.");
    }
}

/**
 he lived as a devil, eh?
 Madmam, I am Adam.
*/