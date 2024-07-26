#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string name("wangdao");
    int age = 100;
    int num = 20;
    [name, age](int value){
        cout << "value = " << value << endl;
        cout << "name = " << name << endl;
        cout << "age = " << age << endl;
    }(300);

    cout << endl;
    [name, age, num](int value){
        cout << "value = " << value << endl;
        cout << "name = " << name << endl;
        cout << "age = " << age << endl;
        cout << "grade = " << num << endl;
    }(300);
    // 将外部变量全部以值传递的形式捕获到lambda表达式中
    [=](int value){
        cout << "value = " << value << endl;
        cout << "name = " << name << endl;
        cout << "age = " << age << endl;
        cout << "grade = " << num << endl;
    }(300);
    
    [name, &num, &age](int value){
        age = 22;
        num = 200;
        cout << "value = " << value << endl;
        cout << "name = " << name << endl;
        cout << "age = " << age << endl;
        cout << "grade = " << num << endl;
    }(300);
}

int main()
{
    test0();
    return 0;
}

