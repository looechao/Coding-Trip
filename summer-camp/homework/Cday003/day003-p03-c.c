#include <stdio.h>

int year1, month1, day1;
int year2, month2, day2;

int main()
{
    printf("请输入第一个年 月 日:");
    scanf("%d %d %d", &year1, &month1, &day1);
    printf("请输入第二个年 月 日:");
    scanf("%d %d %d", &year2, &month2, &day2);

    int interval = 0;
    while ((year1 != year2) || (month1 != month2) || (day1 != day2))
    {
        day1++;
        interval++;
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
    printf("The interval between the 2 days is: %d", interval);
    return 0;
}