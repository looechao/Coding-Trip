#include <stdio.h>

int main()
{
    double init_balance;
    printf("Enter initial balance:");
    scanf("%d", &init_balance);

    int rate;
    printf("Enter interest rate:");
    scanf("%d", &rate);

    int years;
    printf("Enter number of years:");
    scanf("%d", &years);

    double balances[5];
    for (int i = 0; i < 5; i++)
    {
        balances[i] = init_balance;
    }

    int rates[5];
    for (int i = 0; i < 5; i++)
    {
        rates[i] = rate;
    }

    printf("\nyears ");

    for (int i = 0; i < 5; i++)
    {
        printf("%4d%%  ", i);
    }

    printf("\n");

    for(int year=1; year<=years;year++){
        printf("%3d   ", year);
        for(int i=0;i<5;i++){
            balances[i]+=balances[i]*((rate+i)/100);
            printf(" %7d ", balances);
        }
        printf("\n");
    }
    return 0;
}