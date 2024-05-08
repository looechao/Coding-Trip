#include<stdio.h>
#include<stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

int hIndex(int* citations, int n){
   //闭区间：[0,n-1]
	int left = 0, right = n - 1;
    while(left <= right){//注意事项1：left <= right注意等号要不要加
        int mid = left + (right - left >> 1);   //注意事项2
        int cmp = citations[mid]- (n-mid);
        if( cmp >= 0 ){
            right = mid - 1;   //注意事项3
        }else{
            left = mid + 1;   //注意事项4
        }
    }//left > right
    return n-left;
}

int main(){
    int citations[] = {0,1,3,5,6};
    printf("%d ", hIndex(citations,SIZE(citations)));
    return 0;
}