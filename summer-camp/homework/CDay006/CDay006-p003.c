#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
#define MAX 2147483647

bool straight, flush, four, three;
int pairs,max_same_num = 0;

int num_in_suit[4];  // 四种花色
int num_in_rank[13]; // 每个点数有几张

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main()
{
    for (;;)
    {
        // 读取用户输入， 一副手牌，共5张
        read_cards();
        // 分析手牌（计算）
        //初始化上一轮的变量
        straight = false;
        flush = false;
        four = false;
        three = false;
        pairs = 0;
        max_same_num = 0;
        analyze_hand();
        // 输出结果
        print_result();
        // 用户输入零，结束
    }
    return 0;
}

void read_cards(void)
{
    int cards_read = 0;
    // 初始化清空上一轮的手牌结果
    for (int i = 0; i < 4; i++)
    {
        num_in_suit[i] = 0;
    }
    for (int j = 0; j < 13; j++)
    {
        num_in_rank[j] = 0;
    }

    bool in_hand[4][13] = {false};

    while (cards_read < 5)
    {
        bool bad_card = false;
        printf("Enter a card:");
        // 读取用户输入
        char c = getchar();
        int rank;
        switch (c)
        {
        case '0':
            exit(0);
        case '2':
            rank = 0;
            break;
        case '3':
            rank = 1;
            break;
        case '4':
            rank = 2;
            break;
        case '5':
            rank = 3;
            break;
        case '6':
            rank = 4;
            break;
        case '7':
            rank = 5;
            break;
        case '8':
            rank = 6;
            break;
        case '9':
            rank = 7;
            break;
        case 't':
        case 'T':
            rank = 8;
            break;
        case 'j':
        case 'J':
            rank = 9;
            break;
        case 'q':
        case 'Q':
            rank = 10;
            break;
        case 'k':
        case 'K':
            rank = 11;
            break;
        case 'a':
        case 'A':
            rank = 12;
            break;
        default:
            bad_card = true;
            break;
        }
        c = getchar();
        int suit;
        switch (c)
        {
        case 'd':
        case 'D':
            suit = 0;
            break;
        case 'c':
        case 'C':
            suit = 1;
            break;
        case 'h':
        case 'H':
            suit = 2;
            break;
        case 's':
        case 'S':
            suit = 3;
            break;
        default:
            bad_card = true;
            break;
        }

        // 读取剩余字符
        while ((c = getchar())!='\n')
        {
            if (c != ' ' && c != '\n')
            {
                bad_card = true;
            }
        }

        //(rank,suit)->扑克牌
        if (bad_card)
        {
            printf("Bad card, ignored.\n");
        }else if(in_hand[suit][rank]){
            printf("Duplicated card, ignored.\n");
        }else{
            cards_read++;
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            in_hand[suit][rank] = true;
        }
    }
    
    return;
}


void analyze_hand(void){

    int size_of_num_in_rank = SIZE(num_in_rank);
    int size_of_num_in_suit = SIZE(num_in_suit);
    for(int i=0; i< size_of_num_in_rank;i++){
        if(num_in_rank[i] == 2){
            pairs++;
        }
        if(num_in_rank[i] > max_same_num){
            max_same_num = num_in_rank[i];
        }
    }
    if(max_same_num == 1){
        int max = 0;
        int min = MAX;
        for(int i = 0; i < size_of_num_in_rank; i++){
            if(num_in_rank[i] != 0){
                if(i>max){
                    max = i;
                }
                if(i < min){
                    min = i;
                }
            }
        }
        if(abs(max - min) == 4){
            straight = true;
        }
    }
    switch (max_same_num){
        case 4: four = true; break;
        case 3: three = true; break;
    }
    for(int i = 0; i < size_of_num_in_suit; i++){
        if(num_in_suit[i] == 5){
            flush = true;
        }
    }
}

void print_result(void){
    if(straight && flush ){
        printf("straight flush\n"); return;
    }
    if(straight){
        printf("straight\n"); return;
    }
    if(!straight && flush){
        printf("flush\n"); return;
    }
    if(pairs == 2){
        printf("two pair\n"); return;
    }
    if(pairs == 1 && max_same_num == 3){
        printf("full house\n"); return;
    }
    if(pairs == 1){
        printf("one pair\n"); return;
    }
    if(three){
        printf("three of a kind\n"); return;
    }
    if(four){
        printf("four of a kind\n"); return;
    }
    printf("high card\n"); return;
}