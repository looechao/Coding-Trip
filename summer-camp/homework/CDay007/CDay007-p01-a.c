#include<stdio.h>
#define MAX_LEN 128

int main(){
    char str[MAX_LEN];
    printf("Enter a message:");
    int p = 0;
    for(;;){
        char c =getchar();
        if(c!='\n'){
            str[p] = c;
            p++;
        }else{
            str[p] = '\0';
            break;
        }
    }
    printf("Reversal is: ");
    for(int i = p-1; i >= 0; i--){
        printf("%c", str[i]);
    }
    return 0;
}