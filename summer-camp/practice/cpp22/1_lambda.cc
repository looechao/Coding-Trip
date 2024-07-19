#include <iostream>
using std::cout;
using std::endl;

void test0(){
    //[]捕获列表
    //()函数的参数列表
    //{}函数的函数体
    
    int a = 10;

    [a](int value){
        cout << " a === " << a << endl;
        cout << "value = " << value << endl;
    }(200);

    cout << " a = " << a << endl; 
}

int main()
{
    test0();
    return 0;
}

