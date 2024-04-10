#include<stdio.h>
#include<stdbool.h>


int n,m,k,p,count;

int main()
{
    printf("输入人数，第几个出列，从谁开始报数：");
    scanf("%d %d %d",&n,&m,&k);
    bool a[n+1];

    a[0]=false;
    for(int i=1;i<=n;i++)
    {
        a[i]=true;
    }
    int h=1;
    while(p<n)    //模拟报数过程
    {
        if(a[k]==true)   //如果该人未出列
        {
            count++;    //报数
            if(count==m)   //报数报到了m，进行出列
            {
                a[k]=false;
                p++;
                printf("%d出列 ",k);
                count=0;
            }
        }
        k++;
        if(k==n+1)   //实现循环操作
        {
            k=1;
        }
    }
    return 0;
}
