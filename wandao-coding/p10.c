#include<stdio.h>

int n;
int func();

int main()
{
    scanf("%d",&n);
    printf("%d",func(n));
    return 0;
}

int func(int f)
{
    return((f-32)*5/9);
}
