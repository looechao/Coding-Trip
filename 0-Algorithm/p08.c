#include<stdio.h>

int a,b,c;
int count,type;

int main()
{
    scanf("%d %d %d",&a,&b,&c);
    if(a+b<=c||a+c<=b||b+c<=a) {printf("无法构成三角形\n"); return main();}
    if(a*a+b*b==c*c||c*c+b*b==a*a||a*a+c*c==b*b) type++;
    if(a==b&&b==c) {printf("等边三角形\n"); return main();}
    if(a==b&&b!=c) count++;
    if(c==b&&b!=a) count++;
    if(a==c&&c!=b) count++;
    if(count==0&&type!=0)  {printf("直角三角形\n"); return main();}
    if(count!=0&&type!=0)  {printf("等腰直角三角形\n"); return main();}
    if(count!=0&&type==0)  {printf("等腰三角形\n"); return main();}
    return main();
}
