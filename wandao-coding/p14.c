#include<stdio.h>

int count,sum,avg;  //ͳ�Ʋ����������

int main()
{
    int a[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<60)
        {
            count++;
        }
        sum+=a[i];
    }
    avg=sum/10;
    printf("�����������:%d\n����:%d",count,avg);
    return 0;
}
