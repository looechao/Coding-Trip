#include<stdio.h>

int main(){
    int right=0xCAFE,left=0xCAFE;
    right>>=4;
    left<<=12;
    int sum=left+right;

    int mask=0x00FFFF;
    sum&=mask;
    printf("%x", sum);
    return 0;
}