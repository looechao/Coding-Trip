#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


int num_in_suit[4];  //���ֻ�ɫ
int num_in_rank[13];  //ÿ�������м���

void read_cards(void){
    //�����һ�ֵ����ƽ��
    for(int i = 0; i < 4; i++){
        num_in_rank[i]=0;
    }
    for(int j = 0; j < 13; j++){
        num_in_rank[j] = 0;
    }


    return;
}
void analyze_hand(void);
void print_result(void);


int main(){
    for(;;){
    //��ȡ�û����룬 һ�����ƣ���5��
    read_cards();
    //�������ƣ����㣩
    analyze_hand();
    //������
    print_result();
    //�û������㣬����
    }
    return 0;
}