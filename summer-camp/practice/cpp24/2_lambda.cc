#include <iostream>
#include <functional>

using std::string;
using std::cout;
using std::endl;
using std::function;

void test0(){
    int num = 100;
    //void(int) 
    auto f = [&num](int value)->void{
        ++num;
        cout << "num = " << num << endl;
        cout << "value = " << value << endl; 
    };
    f(10);

    function<void(string&, int&)> f2 = [num](string& name, int& value){
        cout << "num = " << num << endl;
        name = "wangdao";
        cout << "name = " << name << endl;
        cout << "value = " << value << endl;
    };

    string nn = "hello";
    int tt = 200;
    f2(nn, tt);
    
}

int main()
{
    test0();
    return 0;
}

