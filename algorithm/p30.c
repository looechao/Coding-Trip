#include<stdio.h>
#include<stdbool.h>


int n,m,k,p,count;

int main()
{
    printf("�����������ڼ������У���˭��ʼ������");
    scanf("%d %d %d",&n,&m,&k);
    bool a[n+1];

    a[0]=false;
    for(int i=1;i<=n;i++)
    {
        a[i]=true;
    }
    int h=1;
    while(p<n)    //ģ�ⱨ������
    {
        if(a[k]==true)   //�������δ����
        {
            count++;    //����
            if(count==m)   //����������m�����г���
            {
                a[k]=false;
                p++;
                printf("%d���� ",k);
                count=0;
            }
        }
        k++;
        if(k==n+1)   //ʵ��ѭ������
        {
            k=1;
        }
    }
    return 0;
}
