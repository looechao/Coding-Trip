#include<stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
#define SWAP(arr, i, j)  {\
    int t = (arr)[(i)];\
    (arr)[(i)] = (arr)[(j)];\
    (arr)[(j)] = t;\
} 

void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapify(int arr[], int i, int n){
    while(i < n){
        //求三个元素的最大值
        int lchild = 2 * i + 1;
        int rchild = 2 * i + 2;
        int maxIdx = i;
        if(lchild < n && arr[lchild] > arr[maxIdx]){
            maxIdx = lchild;
        }
        if(rchild < n && arr[rchild] > arr[maxIdx]){
            maxIdx = rchild;
        }
        if(maxIdx == i) break;
        SWAP(arr, i, maxIdx);
        //调整maxIdx节点
        i = maxIdx;
    }
}


void build_heap(int arr[], int n){
    //构建大顶堆,从后往前开始构建
    //找到第一个非叶子节点 lchild(i) = 2i+1 <= n - 1  i <= (n-2 >> 1)
    for(int i = ( n - 2 >> 1); i >= 0; i--){
        heapify(arr, i, n);
    }
}

void heap_sort(int arr[], int n){
    build_heap(arr, n);
    int len = n;
    while(len > 1){
        SWAP(arr, 0, len - 1);
        len--;
        heapify(arr, 0, len);
    }
}

int main(){
    int arr[] = {28, 27, 43, 3, 9, 83, 20};
    print_array(arr, SIZE(arr));
    heap_sort(arr, SIZE(arr));
    print_array(arr, SIZE(arr));
    return 0;
}