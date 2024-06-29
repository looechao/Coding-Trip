#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    ~A()
    {
        cout<<"A destructed"<<endl;
    }
private:
    int a;
    int b;
};

class B
{
public:
    ~B()
    {
        cout<<"B destructed"<<endl;
    }
private:
    int a;
    int b;
};

class C
{
public:
    ~C()
    {
        cout<<"C destructed"<<endl;
    }
private:
    int a;
    int b;
};


class D
{
public:
    ~D()
    {
        cout<<"D destructed"<<endl;
    }
private:
    int a;
    int b;
};


C c; // 全局区域
int main()
{
    A *pa = new A(); // A 在堆上申请
    B b;  // 局部变量
    static D d; // 全局静态区域
    delete pa;
    return 0;
}

