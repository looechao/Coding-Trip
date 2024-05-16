#include<stdio.h>
#include<stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

typedef int E;

typedef struct node{
    E val;
    struct node* next;
}Node;

void rotateLeft(int arr[], int n, int k){

    int nums[n];

    for(int i = k; i < n; i++){
        nums[i-k] = arr[i]; 
    }

    int p = 0;

    for(int i = n - k; i < n; i++){
        nums[i] = arr[p];
        p++;
    }

    for(int i = 0; i < n; i++){
        arr[i] = nums[i];
    }

    return;
}


int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    rotateLeft(arr, SIZE(arr), 3);
    printf("\n");
    for(int i = 0; i < SIZE(arr); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}