#include<stdio.h>

int n;

int main()
{
    int sum=1;
    scanf("%d",&n); //读入n
    printf("%d=1",n);
    while(n>0)
    {
        for(int i=2;i<=n;i++)   //找到余数的第一个约束
        {
            if(n%i==0)
            {
                printf("*%d",i);
                n/=i;   //将余数存入n
                break;
            }
        }
    }
    return 0;
}
