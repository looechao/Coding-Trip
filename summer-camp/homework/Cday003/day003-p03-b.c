#include <stdio.h>

/**����ĳһ��������գ������һ���������**/

int year, month, day;

int main()
{
    printf("�������� �� ��:");
    scanf("%d %d %d", &year, &month, &day);
    day++;
    if (day == 32)
    {
        day = 1;
        month++;
    }
    if ((day == 31) && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        day = 1;
        month++;
    }
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        if (month == 2 && day == 30)
        {
            day = 1;
            month++;
        }
    }
    else
    {
        if (month == 2 && day == 29)
        {
            day = 1;
            month++;
        }
    }
    if (month == 13)
    {
        year++;
        month = 1;
    }
    printf("%-4d/%2d/%-2d", year, month, day);
    return 0;
}