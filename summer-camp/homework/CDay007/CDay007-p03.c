#include<stdio.h>
#include<string.h>
#define MAX_LEN 256

void remove_filename(char* url){
    char* ptr = url;
    while(*ptr){
        ptr++;
    }
    for(;;){
        ptr--;
        if(*ptr == '/'){
            *ptr = '\0';
            break;
        }
    }
}

int main(){
    char str[MAX_LEN];
    char* p =str;
    printf("Enter url:");
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
    remove_filename(str);
    printf("%s", str);
    return 0;
}