#include<stdio.h>
#include<string.h>

int countalpha,countspace,countnum,countother;

int main()
{
    char s[100]="\0";  //�����ַ�����
    scanf("%[^\n]",s);
    for(int i=0;i<strlen(s);i++)   //ͳ�Ƹ������͵��ַ�����
    {
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')
        {
            countalpha++;
        }
        else if(s[i]==' ')
        {
            countspace++;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            countnum++;
        }
        else
        {
            countother++;
        }
    }
    printf("��ĸ��%d�� �ո�%d�� ���֣�%d�� ������%d��",countalpha,countspace,countnum,countother);
}
