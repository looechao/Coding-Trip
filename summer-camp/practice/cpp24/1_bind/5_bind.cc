#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;
using std::function;

class Example
{
public:
    //隐含在第一个参数的this，Example * const this
    int add(int x, int y)
    {
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }
    /* int data() */
    /* { */

    /* } */
    int data = 100;//C++11可以直接将数据成员进行初始化
};

void test()
{
    Example ex;
    //成员函数add的类型：int(Example *, int, int)
    //bind绑定之后的函数类型：int()
    //function<int(Example *)> f = bind(&Example::add, 
    //                         std::placeholders::_1, 10, 20);
    function<int()> f = bind(&Example::add, &ex, 10, 20);
    cout << "f() = " << f() << endl;

    cout << endl;
    function<int()> f2 = bind(&Example::add, ex, 30, 40);
    cout << "f2() = " << f2() << endl;

}//y/d + 目标行号 + G

int main(int argc, char *argv[])
{
    test();
    return 0;
}

