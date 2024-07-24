#include <iostream>
#include <functional>

using std::string;
using std::bind;
using std::cout;
using std::endl;
using std::function;

int add(int x, int y)
{
    cout << "int add(int, int)" << endl;
    return x + y;
}

void test0(){
    using namespace std::placeholders;
    function<int(int, int)> f = bind(add, _1, _2);
    cout << "f(10, 20) = " << f(10, 20) << endl;  

    cout << endl;
    using namespace std::placeholders;
    function<int(int)> f2 = bind(add, _1, 20);
    cout << "f2(90) = " << f2(90) << endl;  

    cout << endl;
    using namespace std::placeholders;
    function<int(const string &, int)> f3 = bind(add, _2, 10);
    cout << "f3('asdad', 100) = " << f3("asdad", 100) << endl;  
}

int main()
{
    test0();
    return 0;
}

