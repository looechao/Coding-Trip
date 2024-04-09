#include<stdio.h>

int sum,p;

int main()
{
    int a[16];
    for(int i=0;i<16;i++)
    {
        scanf("%d",&a[i]);
    }
    while(p!=17)
    {
        for(int i=1;i<=4;i++)
        {
            int q= 4-i;
            int x= 1 << q;
            sum=a[p+i-1]*x;
        }
        p+=4;
    }
    printf("%d",sum);
    return 0;
}
