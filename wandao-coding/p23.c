#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int count;

int main()
{
    bool flag=false;
    char s[500]="\0";  //��ֵΪ�յ��ַ����飬���ڴ���ַ���
    scanf("%[^\n]s", s);
    for(int i = 0; i < strlen(s); i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            if(flag == false)
            {
                flag = true;
                count++;
            }
        }
        else
        {
            flag = false;
        }
    }
    printf("%d",count);
    return 0;
}
