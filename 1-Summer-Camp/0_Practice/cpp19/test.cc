#include <iostream>
#include <string>
#include <string.h>
using std::string;
using std::cout;
using std::endl;

void test0(){
    char buf[16] = "asdfasg";
    cout << buf << endl;
    strcpy(buf, buf+1);
    cout << buf << endl;
}

int main()
{
    test0();
    return 0;
}

