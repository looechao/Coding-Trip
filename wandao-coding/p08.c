#include<stdio.h>

int a,b,c;
int count,type;

int main()
{
    scanf("%d %d %d",&a,&b,&c);
    if(a+b<=c||a+c<=b||b+c<=a) {printf("�޷�����������\n"); return main();}
    if(a*a+b*b==c*c||c*c+b*b==a*a||a*a+c*c==b*b) type++;
    if(a==b&&b==c) {printf("�ȱ�������\n"); return main();}
    if(a==b&&b!=c) count++;
    if(c==b&&b!=a) count++;
    if(a==c&&c!=b) count++;
    if(count==0&&type!=0)  {printf("ֱ��������\n"); return main();}
    if(count!=0&&type!=0)  {printf("����ֱ��������\n"); return main();}
    if(count!=0&&type==0)  {printf("����������\n"); return main();}
    return main();
}
