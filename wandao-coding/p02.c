#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char c;

int main()
{
    scanf("%c",&c);
    printf("%c",c-32);   //小写字母的ASCII数值比大写的小32
    return 0;
}
