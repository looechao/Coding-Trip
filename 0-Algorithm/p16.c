#include<stdio.h>
#define PI 3.1415926


float s,v,r,h;


int main()
{
    scanf("%f %f",&r,&h);
    s=r*r*PI;
    v=s*h;
    printf("�����:%f\n ���:%f\n",s,v);
    return 0;
}
