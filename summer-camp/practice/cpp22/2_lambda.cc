#include <iostream>
using std::cout;
using std::endl;

void test0(){
    
    int a = 10;
    [a](int value)mutable->void{
        cout << "a = " << a << endl;
        cout << "value = " << value << endl;
    }(100);
}

int main()
{
    test0();
    return 0;
}

