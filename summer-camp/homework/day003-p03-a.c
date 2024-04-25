#include <stdio.h>

/*判断某一年是否为闰年*/

int year;

int main()
{
    printf("请输入需要查询的年份：");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0 )||( year%400 == 0))
    {
        printf("是闰年");
    }else{
        printf("是平年");
    }
    return 0;
}