#include <iostream>
#include <list>
using std::list;
using std::cout;
using std::endl;

void test0(){
    list<int> lst;
    list<int>::iterator iter1 = lst.begin(), iter2 = lst.end();
    while(*iter1 < *iter2){
        cout << "1" << endl;
    }
}

int main()
{
    test0();
    return 0;
}

