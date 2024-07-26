#include<stdio.h>
#include<limits.h>

int max;
int min=INT_MAX;
int main()
{
    int *array =NULL;
    int count=0;
    int input;
    while(scanf("%d",&input)&&input>=0)
    {
        array = realloc(array, (count + 1) * sizeof(int));
        if(array == NULL)
        {
            printf("内存分配失败!\n");
            return 0;
        }
        array[count]=input;
        count++;
    }
    for(int i=0;i<count;i++)
    {
        if(array[i]>=max) max=array[i];
        if(array[i]<=min) min=array[i];
    }
    printf("最高分是%d，最低分是%d",max,min);
    return 0;
}
