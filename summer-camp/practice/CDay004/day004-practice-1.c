#include<stdio.h>

int main(){
    int grade;
    char level='\0';
    scanf("%d", &grade);
    if(grade>100||grade<0){
        printf("Illeagal Grade");
    }else{
            switch(grade/10){
            case 10:
            /*break throgh*/
            case 9:
                level='A';
                break;
            case 8:
                level='B';
                break;
            case 7:
                level='C';
                break;
            case 6:
                level='D';
                break;  
            default:
                level='F';      
            }
        }
    printf("%c", level);
    return 0;
}