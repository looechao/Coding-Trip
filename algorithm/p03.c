#include<stdio.h>
#include<stdlib.h>

int a[3][3],sum;  //存放矩阵与和

int main()
{
    for(int i=0;i<3;i++)    // 读入数组内部元素
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++)    //计算对角线元素
    {
        for(int j=0;j<3;j++)
        {
            if(i==j) sum+=a[i][j];   //累加主对角线元素
        }
    }
    printf("%d",sum);
    return 0;
}
