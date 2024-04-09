#include<stdio.h>

float sum(int n);

int main()
{
    int x;
    scanf("%d",&x);
    printf("%lf",sum(x));
    return 0;
}

float sum(int n)
{
    float sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=1/(float)(2*i);
    }
    return sum;
}
