#include <stdio.h>

/*�ж�ĳһ���Ƿ�Ϊ����*/

int year;

int main()
{
    printf("��������Ҫ��ѯ����ݣ�");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0 )||( year%400 == 0))
    {
        printf("������");
    }else{
        printf("��ƽ��");
    }
    return 0;
}