#include <stdio.h>

int year, month, day;

int main()
{
    int year1=1970,month1=1,day1=1,weekday=4;
    printf("请输入 年 月 日 ：");
    scanf("%d %d %d", &year, &month, &day);
    while((year1!=year)||(month1!=month)||(day1!=day)){
        day1++;
        weekday++;
        weekday%=7;
        if (day1 == 32)
        {
            day1 = 1;
            month1++;
        }
        if ((day1 == 31) && (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11))
        {
            day1 = 1;
            month1++;
        }
        if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0))
        {
            if (month1 == 2 && day1 == 30)
            {
                day1 = 1;
                month1++;
            }
        }
        else
        {
            if (month1 == 2 && day1 == 29)
            {
                day1 = 1;
                month1++;
            }
        }
        if (month1 == 13)
        {
            year1++;
            month1 = 1;
        }
    }
    if(weekday==0){
        printf("这天是星期天\n");
    }else{
        printf("这天是星期%d\n",weekday);
    }
    return 0;
}