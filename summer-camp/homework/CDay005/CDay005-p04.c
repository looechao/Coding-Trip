#include<stdio.h>

int joseph(int n, int m){
    //�߽�����
    if(n==1){
        return 0;
    }else{   //�ݹ�
       return ((joseph(n-1,m))+m)%n;
    }
}

int main(){
    int n,m;
    printf("����������n�ͼ��m:");
    scanf("%d %d", &n, &m);
    printf("�����˵ı���ǣ�%d",joseph(n,m)+1);
}