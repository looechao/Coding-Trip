#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("����������Ԫ�صĸ���:\n");
    scanf("%d",&n);
    int a[n];
    printf("�����������Ԫ��:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n/2;i++)   //�û�Ԫ��λ��
    {
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;
    }
    printf("����:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
