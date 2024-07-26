#include <iostream>

using std::endl;
using std::cout;

class Base
{
public:
    Base(int i)
    {
        b = i;
    }
    
    Base()
    : b(0) 
    {}

    virtual void Print()
    {
        cout << "Base's Print() called." << endl;
    }

protected:
    int b;
};

class Derive1 : public Base
{
public:
    Derive1(int i) 
    : Base(i) 
    {}

    void Print()
    {
        cout << "Derive1's Print() called." << endl;
    }
};

class Derive2 : public Base
{
public:
    Derive2(int i) 
    : Base(i) {}
    
    void Print()
    {
        cout << "Derive2's Print() called." << endl;
    }
};

void fun(Base* obj)
{
    obj->Print();
}

int main(void)
{
    Derive1 d1(1);
    Derive2 d2(2);
    fun(&d1);
    fun(&d2);
    return 0;
}
