#include<iostream>
#include <string>

using namespace std;


int main() {
    string s;
    s.reserve(100);  //Ԥ�ȷ�������100���ַ����ڴ�
    char ch;
    while(cin >> ch)
    {
        s.push_back(ch);
    }

    return 0;
}
