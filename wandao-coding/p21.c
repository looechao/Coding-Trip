#include<stdio.h>

int y,m,d,h,min,s;

int main()
{
    scanf("%d %d %d %d %d %d",&y,&m,&d,&h,&min,&s);
    s++;
    if(s==60)
    {
        min++;
        s=0;
    }
    if(min==60)
    {
        h++;
        min=0;
    }
    if(h==24)
    {
        d++;
        h=0;
    }
    if(d==30)
    {
        if(m==2||y%4==0)   //闰年2月29天
        {
            m++;
            d=1;
        }
    }
    if(d==29)
    {
        if(m==2||y%4!=0)   //平年2月28天
        {
            m++;
            d=1;
        }
    }
    if(d==31)
    {
        if(m==4||m==6||m==9||m==11)
        {
            m++;
            d=1;
        }
    }
    if(d==32)
    {
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        {
            m++;
            d=1;
        }
    }
    if(m==13)
    {
        y++;
        m=1;
    }
    printf("%d年%d月%d日%d时%d分%d秒", y,m,d,h,min,s);
    return 0;
}
