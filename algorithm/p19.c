#include<stdio.h>

int main()
{
    long sum();   //����sum����
    int x;
    scanf("%d",&x);
    printf("%d",sum(x));   //������
    return 0;
}


long sum(int n)    //�ݹ麯��
{
    if(n==1) return 12;
    else return sum(n-1)+n*10+2;
}
