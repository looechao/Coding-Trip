#include<stdio.h>
#define MAX_LEN 128

int main(){
    char str[MAX_LEN];
    printf("Enter a message:");
    char* p = str;
    for(;;){
        char c = getchar();
        if(c != '\n'){
            *p = c;
             p++;
        }else{
            *p = '\0';
            break;
        }
    }
    p--;
    printf("Reversal is:");
    for(;;){
        if(p != str){
            printf("%c", *p);
            p--;
        }else{
            printf("%c", *p);
            break;
        }
    }
    return 0;
}