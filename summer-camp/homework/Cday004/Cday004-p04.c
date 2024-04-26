#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>


char again;

int roll_dices(void){
    int dice1=rand()%6+1;
    int dice2=rand()%6+1;
    return dice1+dice2;
}

bool play_game(void){
    srand(time(NULL));
    int result=roll_dices();
    printf("you rolled:%d\n", result);
    if(result==7||result==11){
        printf("you win!\n");
        return true;
    }else if(result==2||result==3||result==12){
        printf("you lose!\n");
        return false;
    }else{
        int point = result;
        printf("your point is %d\n", point);
        int new_roll=roll_dices();
        printf("you rolled %d\n", new_roll);
        if(new_roll==7){
            printf("you lose!");
            return false;
        }
        do{
            int new_roll=roll_dices();
            printf("you rolled %d\n", new_roll);
            if(new_roll==point){
                printf("you win!\n");
                return true;
            }
            if(new_roll==7){
            printf("you lose!");
            return false;
            }
        }while(new_roll!=7);
    }
}

int main(void){
    int wins=0, losses=0;
    play_game();
    do{
        play_game()? wins++:losses++;
        printf("\nPlay again?");
        again = getchar();
        getchar();
    } while(again == 'y'||again =='Y') ;
    printf("wins:%d losses:%d",wins, losses);
    return 0;    
}