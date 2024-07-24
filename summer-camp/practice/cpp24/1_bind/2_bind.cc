#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

void func(int x1, int x2, int x3, const int &x4, int x5)
{
    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl
         << "x3 = " << x3 << endl
         << "x4 = " << x4 << endl
         << "x5 = " << x5 << endl;
}

/* int gNum = 100; */

void test()
{
    /* func(1, 2, 3, gNum, gNum); */
    int number = 111;
    using namespace  std::placeholders;
    //占位符整体代表的是形参的位置
    //占位符中的数字代表的是实参的位置
    //bind默认采用的是值传递
    //cref = const reference,引用包装器
    //ref = reference,引用包装器
    auto f = bind(&func, 1, _5, _1, std::cref(number), number);

    number = 222;
    //实参进行传递的时候，实参的个数一定要大于等于占位符中
    //的数字的最大值
    f(10, 20, 30, 40, 50, 60, 70);//多余的参数直接丢掉
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

