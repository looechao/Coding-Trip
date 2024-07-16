#include<stdio.h>
#include<time.h>
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

void shuffle(int arr[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int j = rand()%n;
        SWAP(arr,i,j);
    }
}

int main(){
    int arr[] = {28, 27, 43, 3, 9, 83, 20};
    print_array(arr, SIZE(arr));
    shuffle(arr, SIZE(arr));
    print_array(arr, SIZE(arr));
    return 0;
}