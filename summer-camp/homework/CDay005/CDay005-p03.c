#include<stdio.h>

void hanoi(int n, char start, char middle, char target){
    //边界条件，最后一个盘子移动到目标盘子
    if(n==1){
        printf("%c->%c\n", start, target);
        return;
    }
    //递归公式
    //将n-1个盘子，经过目标盘子，移动到中间盘子；
    hanoi(n-1,start,target,middle);
    //将最大的盘子移动到目标盘子
    printf("%c->%c\n", start, target);
    //将n-1个盘子，经过起始盘子，移动到目标盘子；
    hanoi(n-1,middle,start,target);
}

int main(){
    int n;
    printf("请输入圆盘个数：");
    scanf(" %d", &n);
    //打印移动步骤
    hanoi(n,'A','B','C');
    //s(1)=1
    //s(n)=s(n-1)+1+s(n-1)
    //s(n)=2s(n-1)+1
    //s(n)+1=2s(n-1)+2
    //s(1)+1=2  s(n)+1=2^n  s(n)=2^2-1

    //打印移动次数
    printf("Total steps = %lld", (1ll<<n)- 1 );
    return 0;
}