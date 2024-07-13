#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
    Base(int x)
    :_x(x)
    {}
    friend int operator+(const Base& a, const Base& b);
private:
    int _x;
};

int operator+(const Base& a, const Base& b){
    return b._x - a._x;
}


void test0(){
    int i = 2;
    int j = 7;

    Base x(i);
    Base y(j);
    cout << (x + y == j - i) << endl;
}

int main()
{
    test0();
    return 0;
}

