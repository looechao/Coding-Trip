#include<stdio.h>

int joseph(int n, int m){
    //边界条件
    if(n==1){
        return 0;
    }else{   //递归
       return ((joseph(n-1,m))+m)%n;
    }
}

int main(){
    int n,m;
    printf("请输入人数n和间隔m:");
    scanf("%d %d", &n, &m);
    printf("存活的人的编号是：%d",joseph(n,m)+1);
}