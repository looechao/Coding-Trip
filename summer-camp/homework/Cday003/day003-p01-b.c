#include<stdio.h>

int main(){
    int left=0xCAFE,right=0xCAFE;
    left<<=8;
    right>>=8;
    
    int sum=left+right;

    int mask=0x00FFFF;
    sum&=mask;
    printf("%x",sum);
    return 0;
}