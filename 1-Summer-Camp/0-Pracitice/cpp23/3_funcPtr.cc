#include <iostream>
using std::cout;
using std::endl;

int func0(){
    return 0;
}

int func1(){
    return 1;
}


void test0(){
    /* typedef int(*pFunc)(); */ //C语法
    /* typedef int(*)() pFunc; */

    using pFunc = int(*)();

    pFunc f = func0;
    cout << *f << endl;
}

int main()
{
    test0();
    return 0;
}

