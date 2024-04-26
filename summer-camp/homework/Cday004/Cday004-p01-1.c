#include<stdio.h>

/*用异或运算找出只出现了一次的元素*/

int main(){
    int nums[5] = {1,4,2,1,2};
    int xor=0;
    for(int i=0; i<5; i++){
        xor^=nums[i];
    }
    printf("%d", xor);
    return 0;
}