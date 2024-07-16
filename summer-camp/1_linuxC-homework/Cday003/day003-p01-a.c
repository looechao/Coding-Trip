#include<stdio.h>

int main(){
    int n = 0xCAFE;
    int mask=0x000F;
    int result = mask & n;
    if(result==0xF||result==0x7||result==0xB||result==0xD||result==0xE){
        printf("至少有三个1");
    }
    return 0;
}