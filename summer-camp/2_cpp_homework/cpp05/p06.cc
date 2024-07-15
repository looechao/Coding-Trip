#include <iostream>
using std::cout;
using std::endl;
using std::string;


void test0(){
    string str;
    string str2("hello,");
    string str3("wolrd!",5);
    string str4(str2);
    string str5(str2, 0, 3);
    string str6(5, 'a');
    
    cout << str << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
    cout << str6 << endl;
}

int main()
{
    test0();
    return 0;
}

