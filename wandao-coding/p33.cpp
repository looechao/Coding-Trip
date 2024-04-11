#include<iostream>
#include<cstdio>

using namespace std;

class Tree{
private:
    int ages;  //树龄
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
    cout<<"请输入当前树龄和需要增长的年限：";
    cin>>x>>y;
    Tree t1(x);
    cout<<"增长三十年后的树龄是:"<<t1.grow(y)<<endl;;
}
