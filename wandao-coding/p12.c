#include<stdio.h>

int n;

int main()
{
    scanf("%d",&n);  //����n��ֵ
    int a[n+1];
    a[n]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&a[n]);  //�����n+1��Ԫ�ص�ֵ
    for(int i=n;i>0;i--)   //�Ӻ���ǰ�Ƚϲ�����
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
