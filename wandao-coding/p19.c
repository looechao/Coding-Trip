#include<stdio.h>

int main()
{
    long sum();   //声明sum函数
    int x;
    scanf("%d",&x);
    printf("%d",sum(x));   //输出结果
    return 0;
}


long sum(int n)    //递归函数
{
    if(n==1) return 12;
    else return sum(n-1)+n*10+2;
}
