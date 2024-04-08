#include<stdio.h>

int count,sum,avg;  //统计不及格的人数

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
    printf("不及格的人数:%d\n均分:%d",count,avg);
    return 0;
}
