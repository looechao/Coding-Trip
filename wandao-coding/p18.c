#include<stdio.h>

int main()
{
    for(int i=0;i<5;i++)
    {
        int x=i+1;
        for(int j=0;j<5;j++)
        {
            if(x!=1)  //xû�м���1ʱ�������x��ֵ
            {
                printf("%d",x);
                x--;
            }
            else  //x����1�����1
                printf("1");
        }
        printf("\n");
    }
    return 0;
}
