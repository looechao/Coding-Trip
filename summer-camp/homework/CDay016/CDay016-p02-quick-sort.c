#include<stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int left, int right){
    //1.选取基准值
    int pivot = arr[left];
    //2.双向分区
    int i = left, j = right;
    while(i < j){
        while(i < j && arr[j] >= pivot){
            j--;
        }// i == j || arr[j] < pivot
        arr[i] = arr[j];

        //再移动i，找>pivot的元素
        while(i < j && arr[i] <= pivot){
            i++;
        }// i == j || arr[i] > pivot
        arr[j] = arr[i];
    }// i == j
    arr[i] = pivot;
    return i;
}

void q_sort(int arr[], int left, int right){
    //边界条件
    if(left >= right) return;
    //递归公式
    //1.分区
    int idx = partition(arr, left, right);
    //2.对左边区间进行排序
    q_sort(arr, left, idx-1);
    //3.对右边区间排序
    q_sort(arr, idx+1, right);
}

void quick_sort(int arr[], int n){
    //通过委托实现
    q_sort(arr, 0, n - 1);
}

int main(){
    int arr[] = {28, 27, 43, 3, 9, 83, 20};
    print_array(arr, SIZE(arr));
    quick_sort(arr, SIZE(arr));
    print_array(arr, SIZE(arr));
    return 0;
}