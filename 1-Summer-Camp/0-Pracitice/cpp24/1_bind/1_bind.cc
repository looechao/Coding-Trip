#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

//在C语言中，函数名就是函数的入口地址
//在C语言中，数组名也是数组的入口地址
int add(int x, int y)
{
    cout << "int add(int, int)" << endl;
    return x + y;
}

int multiply(int x, int y, int z)
{
    cout << "int multiply(int, int, int)" << endl;
    return x * y * z;
}

class Example
{
public:
    //隐含在第一个参数的this，Example * const this
    int add(int x, int y)
    {
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }
};
void test()
{
    auto f = bind(add, 1, 2);
    cout << "f() = " << f() << endl;

    cout << endl;
    auto f2 = bind(&multiply, 3, 4, 5);
    cout << "f2() = " << f2() << endl;

    cout << endl;
    Example ex;
    auto f3 = bind(&Example::add, &ex, 10, 20);
    cout << "f3() = " << f3() << endl;

    cout << endl;
    //占位符
    using namespace std::placeholders;
    auto f4 = bind(add, _2, 1001);
    cout << "f4(999) = " << f4(999, 777) << endl;
}

int main(int argc, char *argv[])
{
    test();
    /* printf("%p\n", main); */
    /* printf("%p\n", &main); */
    return 0;
}

