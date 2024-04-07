#include<stdio.h>


int n,count;

int main()
{
    int sum=1;
    int *array=NULL; //定义一个空数组
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            array = realloc(array,(count + 1)*sizeof(int));
            array[count] = 1;
            sum*=array[count];
            count++;
            if(sum == n) break;
        }
        else
        {
            if(n%i==0&&i==2)
            {
                sum*=2;
                array[count] = i;
                sum*=array[count];
                count++;
                if(sum == n) break;
            }
            if(n%i==0&&i!=2)
            {
                array[count] = i;
                sum*=array[count];
                count++;
                if(sum == n) break;
            }
        }
        if(sum == n) break;
    }
    printf("%d \n",sum);
    for(int i=0;i<count;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}
