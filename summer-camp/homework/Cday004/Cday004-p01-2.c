#include<stdio.h>

int main(){
    int nums[6] = {1,2,1,3,2,5};

    int xor = 0;
    for(int i=0; i<6; i++){
        xor ^= nums[i];  
    }
    
    int lsb = xor&(~xor+1);    //last set bit;a与b在这一位上不同

    int a=0,b=0;
    for(int i=0;i<6;i++){
        if(lsb&nums[i]){
            a^=nums[i];
        }else{
            b^=nums[i];
        }
    }
    printf("[%d %d]", a,b);
    return 0;
}