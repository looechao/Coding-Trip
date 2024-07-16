#include <iostream>
using std::cout;
using std::endl;

template <class T>
T add(T t1, T t2){
    return t1 + t2;
}


void test0(){
    short s1 = 1, s2 = 2;
    int i1 = 1, i2 = 4;
    long l1 = 5, l2 = 6;
    double d1 = 1.1, d2 = 2.2;

    cout << "add(s1, s2):" << add(s1, s2) << endl;
    cout << "add(i1, i2):" << add(i1, i2) << endl;
    cout << "add(l1, l2):" << add(l1, l2) << endl;
    cout << "add(d1, d2):" << add(d1, d2) << endl;
}

int main()
{
    test0();
    return 0;
}

