#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>


int main(){
    const char suits[4]={'S','H','C','D'};
    const char ranks[13]={'2','3','4','5','6','7','8','9','T','J','Q','A'};

    int cards;
    printf("Enter number of cards in hand:");
    scanf("%d", &cards);

    bool in_hands[4][13]={false};
    
    //·¢ÅÆ
    printf("your hands:");

    srand(time(NULL));
    while(cards){
        int i=rand()%4;
        int j=rand()%13;
        if(!in_hands[i][j]){
            in_hands[i][j]=true;
            cards--;
            printf("%c%c ",suits[i],ranks[j]);
        }
    }

    return 0;
}