#include<iostream>
#include<cstdio>

using namespace std;

class Tree{
private:
    int ages;  //����
public:
    Tree(int ages)
    {
        this->ages=ages;
    }
    int grow(int years)
    {
        return ages+years;
    }
};

int main()
{
    int x,y;
    cout<<"�����뵱ǰ�������Ҫ���������ޣ�";
    cin>>x>>y;
    Tree t1(x);
    cout<<"������ʮ����������:"<<t1.grow(y)<<endl;;
}
