#include<stdio.h>

int sum,p;

int main()
{
    char s[16]=("^[\0]");
    char a[16];
    scanf("%s",s);   //读入字符串
    for(int i=0;i<16;i++)
    {
        int n=s[i]-'0';   //将单个字符转换成数字
        a[i] = n;   //赋值给a
    }
    while(p<=12)    //计算二进制求和
    {
        for(int i=1;i<=4;i++)
        {
            int q= 4-i;
            int x= 1 << q;   //求2的q次方
            sum+=a[p+i-1]*x;
        }
        p+=4;
    }
    printf("%d",sum);
    return 0;
}
