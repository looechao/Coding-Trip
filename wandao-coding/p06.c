#include <stdio.h>

int x;  //�û�ָ������

int main()
{
    int a=0,b=1;
    scanf("%d",&x);   //����x
    for(int i=0;;i++)
    {
        if(i==0)
        {
            printf("%d ",a);
        }
        if(i==1)
        {
            printf("%d ",b);
        }
        if(i>1)
        {
            printf("%d ",a+b);
            int temp=a+b;
            a=b;
            b=temp;
        }
        if(a+b>x) break;
    }
    return 0;
}
