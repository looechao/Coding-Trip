#include<stdio.h>

int sum,p;

int main()
{
    char s[16]=("^[\0]");
    char a[16];
    scanf("%s",s);   //�����ַ���
    for(int i=0;i<16;i++)
    {
        int n=s[i]-'0';   //�������ַ�ת��������
        a[i] = n;   //��ֵ��a
    }
    while(p<=12)    //������������
    {
        for(int i=1;i<=4;i++)
        {
            int q= 4-i;
            int x= 1 << q;   //��2��q�η�
            sum+=a[p+i-1]*x;
        }
        p+=4;
    }
    printf("%d",sum);
    return 0;
}
