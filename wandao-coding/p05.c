#include<stdio.h>
#include<stdlib.h>

int grade;

int main()
{
    scanf("%d",&grade);
    if(grade>=90&&grade<=100) printf("A（优秀）\n");
    if(grade>=80&&grade<=89) printf("B(良好)\n");
    if(grade>=70&&grade<=79) printf("C(中等)\n");
    if(grade>=60&&grade<=69) printf("D(合格)\n");
    return 0;
}
