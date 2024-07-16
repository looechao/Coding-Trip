#include <iostream>
using std::cout;
using std::endl;

// define class template
template <class T>
class A{
public:
    A(T val)
    :_val(val)
    {}
    
    void print(){
        cout << "value:" << _val << endl;
    }
private:
    T _val;
};

void test0(){
    A<int> a1(10);
    A<double> a2(10.57);
    a1.print();
    a2.print();
}

int main()
{
    test0();
    return 0;
}

