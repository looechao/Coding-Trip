#include<stdio.h>

int main()
{
    for(int i=0;i<5;i++)
    {
        int x=i+1;
        for(int j=0;j<5;j++)
        {
            if(x!=1)  //x没有减到1时，先输出x的值
            {
                printf("%d",x);
                x--;
            }
            else  //x减到1，输出1
                printf("1");
        }
        printf("\n");
    }
    return 0;
}
