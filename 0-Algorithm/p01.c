#include<stdio.h>
#include<stdlib.h>

int y,x;

int main()
{
    scanf("%d",&x);
    if(x<5) y=x;
    if(x>=5&&x<15) y=x+6;
    if(x>=15) y=x-6;
    printf("%d",y);
	return 0;
}
