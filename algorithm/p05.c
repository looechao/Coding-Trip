#include<stdio.h>
#include<stdlib.h>

int grade;

int main()
{
    scanf("%d",&grade);
    if(grade>=90&&grade<=100) printf("A�����㣩\n");
    if(grade>=80&&grade<=89) printf("B(����)\n");
    if(grade>=70&&grade<=79) printf("C(�е�)\n");
    if(grade>=60&&grade<=69) printf("D(�ϸ�)\n");
    return 0;
}
