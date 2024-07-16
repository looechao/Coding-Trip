#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int && rr = 10;
    int & lr  = rr;
    int && rr1 = rr;
}

int main()
{
    test0();
    return 0;
}

