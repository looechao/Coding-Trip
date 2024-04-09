#include<stdio.h>
#include<string.h>

int countalpha,countspace,countnum,countother;

int main()
{
    char s[100]="\0";  //定义字符数组
    scanf("%[^\n]",s);
    for(int i=0;i<strlen(s);i++)   //统计各种类型的字符个数
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
    printf("字母：%d个 空格：%d个 数字：%d个 其他：%d个",countalpha,countspace,countnum,countother);
}
