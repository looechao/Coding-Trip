#include<stdio.h>

/*����������ҳ�ֻ������һ�ε�Ԫ��*/

int main(){
    int nums[5] = {1,4,2,1,2};
    int xor=0;
    for(int i=0; i<5; i++){
        xor^=nums[i];
    }
    printf("%d", xor);
    return 0;
}