#include <iostream>

using std::cout;
using std::endl;

void test0(){
    int num = 100;
    auto f = [&num](int value){
        ++num;
        cout << "num = " << num << endl;
        cout << "value = " << value << endl;
    };
    f(10);
    f(30);
}

int main()
{
    test0();
    return 0;
}

