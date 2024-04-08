#include<stdio.h>

char c;

int main()
{
    scanf("%c",&c);
    int x=c;
    if(x>=97&&x<=122)
    {
        printf("Ð¡Ð´×ÖÄ¸");
        return 0;
    }
    if(x>=65&&x<=90)
    {
        printf("´óÐ´×ÖÄ¸");
        return 0;
    }
    printf("²»ÊÇ×ÖÄ¸");
    return 0;
}
