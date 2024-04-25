#include<stdio.h>

int main()
{
    int i =1;
    int j=2;
    int k = ++i+j++;
    printf("%d %d %d", i,j,k);
    return 0;
}