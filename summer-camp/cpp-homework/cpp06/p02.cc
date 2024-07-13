#include <iostream>
#include <string.h>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

void test0(){
    char a[200] = {0};
    cin.getline(a, 200, ' ');
    cout << a;
}

int main()
{
    test0();
    return 0;
}

