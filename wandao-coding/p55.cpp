#include<iostream>
#include <string>

using namespace std;


int main() {
    string s;
    s.reserve(100);  //预先分配至少100个字符的内存
    char ch;
    while(cin >> ch)
    {
        s.push_back(ch);
    }

    return 0;
}
