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
        ages+=years;
    }
    void showage()
    {
        cout<<"�������������:"<<ages<<endl;;
    }
};

int main()
{
    int x,y;
    cout<<"�����뵱ǰ�������Ҫ���������ޣ�";
    cin>>x>>y;
    Tree t1(x);
    t1.grow(y);
    t1.showage();
}
