#include<stdio.h>
#define SIZE(a) sizeof(a)/sizeof(a[0])

void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
    printf("a=%d,b=%d\n",a,b);
    return 0;
}

void clear(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
}

int main(void){
    // int a = 3, b = 4;
    // printf("a=%d,b=%d\n",a,b);
    // swap(a,b);
    // printf("a=%d,b=%d",a,b);

    int arr[]={1,2,3,4};
    clear(arr,SIZE(arr));
    for(int i=0;i<SIZE(arr);i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}