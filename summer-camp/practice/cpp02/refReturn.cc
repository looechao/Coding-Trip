#include <iostream>
using std::cout;
using std::endl;

int func1(){
    int num = 100;
    return num;
}

int gNum = 10;
int func2(){
    return gNum;
}

void test0(){
    cout << func1() << endl;
    // func2 的返回值是全局变量gNum的副本
    cout << func2() << endl;

    int a = 1, b = 2;
    &(a+b);
}

int main()
{
    test0();
    return 0;
}

