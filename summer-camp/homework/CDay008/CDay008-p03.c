#include<stdio.h>

typedef enum {
    January=1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
} Month;

int days_in_month(Month m){
    switch (m){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
        return 28;
    default: 
        return 30;
    }
}

int main(void){
    Month my_month = January;
    printf("The number of days in the month: %d\n", days_in_month(my_month));
    return 0;
}