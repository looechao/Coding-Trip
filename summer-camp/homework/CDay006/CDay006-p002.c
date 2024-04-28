#include<stdio.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
int MAX1 = -2147483648;
int MAX2 = -2147483648;

void find_two_largest(int arr[], int n, int* largest, int* second_largest){
    for(int i = 0; i < n; i++){
        if(arr[i]>MAX1){
            MAX1 = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i]>MAX2 && arr[i]<MAX1){
            MAX2 = arr[i];
        }
    }
    *largest = MAX1;
    *second_largest = MAX2;
    return;
}

int main(){
    int n = 0;
    int the_largest;
    int the_second_largest;
    int* largest_ptr = &the_largest;
    int* second_ptr = &the_second_largest;
    printf("Please enter the number of the array:");
    scanf("%d", &n);
    int nums[n];
    printf("Please enter the number:");
    for(int i = 0; i < n; i++){
        scanf(" %d", &nums[i]);
    }
    find_two_largest(nums, SIZE(nums), largest_ptr, second_ptr);
    printf("the largest number is %d\n the second largest number is %d", the_largest, the_second_largest);
    return 0;
}