#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("请输入数组元素的个数:\n");
    scanf("%d",&n);
    int a[n];
    printf("请输入数组的元素:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n/2;i++)   //置换元素位置
    {
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    printf("逆序:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
