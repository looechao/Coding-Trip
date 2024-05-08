#include<stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0])) 


//指针惯用法
int binary_search_last(int arr[], int n, int key){
    //闭区间：[0,n-1]
	int left = 0, right = n - 1;
    while(left <= right){//注意事项1：left <= right注意等号要不要加
        int mid = left + (right - left >> 1);   //注意事项2
        int cmp = key - arr[mid];
        if( cmp < 0 ){
            right = mid - 1;   //注意事项3
        }else if(cmp > 0){
            left = mid + 1;   //注意事项4
        }else{
            int* p = &arr[mid];
            while(*p == key){
                p++;
                mid++;
            }
            return mid;;
        }
    }//left > right
    return -1;
}


//二分法
int binary_search_last2(int arr[], int n, int key){
    //闭区间：[0,n-1]
	int left = 0, right = n - 1;
    while(left <= right){//注意事项1：left <= right注意等号要不要加
        int mid = left + (right - left >> 1);   //注意事项2
        int cmp = key - arr[mid];
        if( cmp < 0 ){
            right = mid - 1;   //注意事项3
        }else if(cmp > 0){
            left = mid + 1;   //注意事项4
        }else{
            if(mid!=n && arr[mid+1] == key){
                right++;
            }else{
                return mid;
            }
        }
    }//left > right
    return -1;
}


//循环+指针
int binary_search_last_front(int arr[], int n, int key){
    //闭区间：[0,n-1]
	int left = 0, right = n - 1;
    while(left <= right){//注意事项1：left <= right注意等号要不要加
        int mid = left + (right - left >> 1);   //注意事项2
        int cmp = key - arr[mid];
        if( cmp < 0 ){
            right = mid - 1;   //注意事项3
        }else if(cmp > 0){
            left = mid + 1;   //注意事项4
        }else{
            if(mid == 0){
                return -1;
            }else{
                int* p = &arr[mid];
                while(*p == key){
                    p--;
                    mid--;
            }
            return mid+1;
        }
        }
    }//left > right
    return -1;
}

//二分法
int binary_search_last_front2(int arr[], int n, int key){
    //闭区间：[0,n-1]
	int left = 0, right = n - 1;
    while(left <= right){//注意事项1：left <= right注意等号要不要加
        int mid = left + (right - left >> 1);   //注意事项2
        int cmp = key - arr[mid];
        if( cmp < 0 ){
            right = mid - 1;   //注意事项3
        }else if(cmp > 0){
            left = mid + 1;   //注意事项4
        }else{
            if(mid!=n && arr[mid-1] == key){
                left--;
            }else{
                return mid;
            }
        }
    }//left > right
    return -1;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 80, 90, 90, 90, 90, 90, 100};
    printf("%d ", binary_search_last_front2(arr, SIZE(arr), 90));
    return 0;
}