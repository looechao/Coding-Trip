#include<stdio.h>
#include<stdlib.h>

int a[3][3],sum;  //��ž������

int main()
{
    for(int i=0;i<3;i++)    // ���������ڲ�Ԫ��
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++)    //����Խ���Ԫ��
    {
        for(int j=0;j<3;j++)
        {
            if(i==j) sum+=a[i][j];   //�ۼ����Խ���Ԫ��
        }
    }
    printf("%d",sum);
    return 0;
}
