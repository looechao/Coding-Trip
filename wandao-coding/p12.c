#include<stdio.h>

int n;

int main()
{
    scanf("%d",&n);  //输入n的值
    int a[n+1];
    a[n]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&a[n]);  //输入第n+1个元素的值
    for(int i=n;i>0;i--)   //从后往前比较并排序
    {
        int temp=a[i-1];
        if(a[i-1]>a[i])
        {
            a[i-1]=a[i];
            a[i]=temp;
        }
    }
    for(int i=0;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
