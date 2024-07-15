#include<stdio.h>

void hanoi(int n, char start, char middle, char target){
    //�߽����������һ�������ƶ���Ŀ������
    if(n==1){
        printf("%c->%c\n", start, target);
        return;
    }
    //�ݹ鹫ʽ
    //��n-1�����ӣ�����Ŀ�����ӣ��ƶ����м����ӣ�
    hanoi(n-1,start,target,middle);
    //�����������ƶ���Ŀ������
    printf("%c->%c\n", start, target);
    //��n-1�����ӣ�������ʼ���ӣ��ƶ���Ŀ�����ӣ�
    hanoi(n-1,middle,start,target);
}

int main(){
    int n;
    printf("������Բ�̸�����");
    scanf(" %d", &n);
    //��ӡ�ƶ�����
    hanoi(n,'A','B','C');
    //s(1)=1
    //s(n)=s(n-1)+1+s(n-1)
    //s(n)=2s(n-1)+1
    //s(n)+1=2s(n-1)+2
    //s(1)+1=2  s(n)+1=2^n  s(n)=2^2-1

    //��ӡ�ƶ�����
    printf("Total steps = %lld", (1ll<<n)- 1 );
    return 0;
}