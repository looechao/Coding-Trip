#include<stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

void selection_sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int min = arr[i];
        int min_idx = i;
        for(int j = i; j < n; j++){
            if(arr[j] < min){
                min = arr[j];
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        //i表示要插入的元素的索引
        int value = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > value){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}


void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {16, 1, 45, 23, 99, 2, 18, 67, 42, 10};
    print_array(arr, SIZE(arr));
    insertion_sort(arr, SIZE(arr));
    print_array(arr, SIZE(arr));
    return 0;
}