#include<stdio.h>

char c;

int main()
{
    scanf("%c",&c);
    int x=c;
    if(x>=97&&x<=122)
    {
        printf("Сд��ĸ");
        return 0;
    }
    if(x>=65&&x<=90)
    {
        printf("��д��ĸ");
        return 0;
    }
    printf("������ĸ");
    return 0;
}
