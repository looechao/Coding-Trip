#include<stdio.h>

int n;

int main()
{
    int sum=1;
    scanf("%d",&n); //¶ÁÈën
    printf("%d=1",n);
    while(n>0)
    {
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                printf("*%d",i);
                n/=i;
                break;
            }
        }
    }
    return 0;
}
