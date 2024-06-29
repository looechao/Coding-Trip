#include <iostream>
using std::out;
using std::endl;

int main()
{
    int num = 1;
    int & ref = num;
    ref += 10;
    cout << num << endl;
    cout << ref << endl;
    cout << &num << endl;
    cout << &ref << endl;
    return 0;
}

