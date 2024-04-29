#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 256

int main()
{
    char min_string[20];
    char max_string[20];
    for(int i = 0; i < 20; i++){
        min_string[i] = 127;
        max_string[i] = 0;
    }
    for (;;){
        bool four_characters = false;
        printf("Enter a word:");
        char str[MAX_LEN];
        char* ptr = str;
        for(;;){
            char c = getchar();
            if(c != '\n'){
                *ptr = c;
                ptr++;
            } else {
                *ptr = '\0'; 
                if(strlen(str) == 4){
                    four_characters = true;
                }
                break;
            }
        }
        if(strcmp(str,min_string)<0){
            strcpy(min_string,str);
        }
        if(strcmp(max_string,str)<0){
            strcpy(max_string,str);
        }
        if(four_characters){
        break;
        }
    }
    printf("\nSmallest word: %s\n", min_string);
    printf("Largest word: %s\n", max_string);
    return 0;
}