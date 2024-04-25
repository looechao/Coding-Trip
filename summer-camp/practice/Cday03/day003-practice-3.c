#include<stdio.h>
#include<math.h>
#include <stdbool.h>


//¸ßÄÚ¾ÛµÍñîºÏ
bool is_prime(int n){
    int rt = sqrt(n);  //squre root
    for(int i=2; i <=rt;i++){
        if(n%i==0){
            return true;
        }
    }
    return false;
}

int main(void){
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    if(is_prime(n)){
        printf("Prime");
    }else{
        printf("Not Prime");
    }
}