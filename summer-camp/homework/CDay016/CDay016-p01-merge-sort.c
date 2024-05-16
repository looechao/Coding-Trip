#include<stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
#define N 7

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void merge(int arr[], int left, int mid, int right){
    int tmp[N];
    int i = left, j = mid + 1, k = 0; // 这里使 'k' 从零开始

    // 比较并合并 'arr[left...mid]' 和 'arr[mid+1...right]'
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }else{
            tmp[k++] = arr[j++];
        }
    }

    // 如果 'arr[left...mid]' 有剩余元素
    while(i <= mid){
        tmp[k++] = arr[i++];
    }

    // 如果 'arr[mid+1...right]' 有剩余元素
    while(j <= right){
        tmp[k++] = arr[j++];
    }

    // 将排好序的 'tmp[0...k-1]' 复制回 'arr[left...right]'
    for(i = left, k = 0; i <= right;){
        arr[i++] = tmp[k++];
    }
}

void m_sort(int arr[], int left, int right){
    //边界条件
    if(left >= right) return;
    //递归公式
    int mid = left + (right - left >> 1);
    //对左边进行排序
    m_sort(arr, left, mid);
    //对右边进行排序
    m_sort(arr, mid+1, right);
    //归并操作
    merge(arr, left, mid, right);
}

void merge_sort(int arr[], int n){
    //委托实现
    m_sort(arr, 0, n - 1);
}

int main(void){
    int arr[N] = {28, 27, 43, 3, 9, 83, 20};
    print_array(arr, SIZE(arr));
    merge_sort(arr, SIZE(arr));
    print_array(arr, SIZE(arr));
    return 0;
}
