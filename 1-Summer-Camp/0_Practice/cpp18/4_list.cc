#include <iostream>
#include <list>
using std::list;
using std::cout;
using std::endl;

void test0(){
    list<int> number(10, 3);
    for(auto &ele : number)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

