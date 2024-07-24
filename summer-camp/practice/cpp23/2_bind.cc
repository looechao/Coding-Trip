#include <iostream>
#include <functional>

using std::bind;
using std::cout;
using std::endl;

class Example{
public:
    // 隐含在第一个参数的指针this, Example* const this;

   int add(int x, int y){
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }
};

int multiply(int x, int y, int z){
    cout << "int multiply (int, int, int)" << endl;
    return x * y * z;
}


int add(int x, int y){
    cout << "int add(int, int)" << endl;
    return x + y;
}


void test0(){
    auto f = bind(add, 1, 2);
    cout << "f() = " << f() << endl;
    
    auto f2 = bind(multiply, 1, 2, 3);
    cout << "f2() = " << f2() << endl;
    
    Example ex;
    auto f3 = bind(&Example::add, &ex, 10, 20);
    cout << "f3() = " << f3() << endl;
}

int main()
{
    test0();
    return 0;
}

