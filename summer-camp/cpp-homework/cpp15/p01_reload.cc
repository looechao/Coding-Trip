#include <iostream>
using std::cout;
using std::endl;

template <class T>
T add(T t1, T t2){
    return t1 + t2;
}


template <class T1, class T2>
T1 add(T1 t1, T2 t2){
    return t1 + t2;
}

//普通函数先于模板函数
short add(short s1, short s2){
    cout << "add(short, short)" << endl;
    return s1+s2;
}

void test0(){
    short s1 = 1, s2 = 2;
    int i1 = 1, i2 = 4;
    long l1 = 5.00, l2 = 6;
    double d1 = 1.1, d2 = 2.2;

    cout << "add(s1, s2):" << add(s1, s2) << endl;
    cout << "add(i1, d1):" << add(i1, d1) << endl;
    cout << "add(d1, i1):" << add(d1, i1) << endl;
    cout << add(s1,s2) << endl;
}

int main()
{
    test0();
    return 0;
}

