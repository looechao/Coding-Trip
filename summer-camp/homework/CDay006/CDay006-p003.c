#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


int num_in_suit[4];  //四种花色
int num_in_rank[13];  //每个点数有几张

void read_cards(void){
    //清空上一轮的手牌结果
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
    //读取用户输入， 一副手牌，共5张
    read_cards();
    //分析手牌（计算）
    analyze_hand();
    //输出结果
    print_result();
    //用户输入零，结束
    }
    return 0;
}