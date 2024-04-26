#include<stdio.h>

int main(){
    int init_balance;
    printf("Enter initial balacne:");
    scanf("%d", &init_balance);
    float balances[5];
    for(int i=0;i<5;i++){
        balances[i]=init_balance;
    }
    int rate;
    printf("Enter interest rate:");
    scanf("%d", &rate);


    int years;
    printf("Enter number of years:");
    scanf("%d", &years);
    
    printf("years");
    for(int i=0; i<5;i++){
        printf("%4d%%  ", rate+i);
    }

    for(int year=0;year<years;year++){
        printf("\n%3d  ",year+1);
        for(int i=0;i<5;i++){
            balances[i]+=balances[i]*((rate+i)/100.0);
            printf("%7.2lf", balances[i]);
        }
    }

    return 0;
}