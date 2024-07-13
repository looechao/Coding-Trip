#include <iostream>
#include <string>

using namespace std;

void test0(){
    string str1 = "hello,world!!!!";
    string str2 = "hello,world!!!!!";
    cout << &str1 << endl;
    printf("%p\n", &str1[0]);
    cout << &str2 << endl;
    printf("%p\n", &str2[0]);

}

int main()
{
    test0();
    return 0;
}

