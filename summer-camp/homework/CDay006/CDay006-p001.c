#include <stdio.h>

void split_time(long total_sec, int *hour, int *minute, int *second)
{
    *hour = total_sec / 3600;
    *minute = (total_sec % 3600) / 60; 
    *second = (total_sec % 3600) % 60; 
}

int main()
{
    long second;
    int h, m, s;
    int *hp = &h;
    int *mp = &m;
    int *sp = &s;
    printf("请输入需要计算的秒数:");
    scanf(" %ld", &second);
    split_time(second, hp, mp, sp);
    printf("%2.2d:%2.2d:%2.2d", h, m, s);
    return 0;
}