#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

//声明函数模板
template<typename T>
T add(T p1, T p2);


//特化函数函数模板
template<>
const char* add<const char*>(const char* p1, const char* p2)
{
    char* ptmp = new char[strlen(p1) + strlen(p2) + 1]();
    strcpy(ptmp, p1);
    strcat(ptmp, p2);
    return ptmp;
}

void test0(){
    const char* p = add<const char*>("hello", ",world");
    cout << p << endl;
    delete []p;
}

int main()
{
    test0();
    return 0;
}

