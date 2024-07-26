#include <iostream>
#include <vector>
#include <iterator>

using std::reverse_iterator;
using std::vector;
using std::cout;
using std::endl;

void test0(){
    vector<int> vec = {1, 3, 5, 7, 9, 8};
    vector<int>::iterator it = vec.begin();
    for(;it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    vector<int> vec = {1, 3, 5, 7, 9, 8};
    vector<int>::reverse_iterator rit = vec.rbegin();
    for(;rit != vec.rend(); ++rit){
        cout << *rit << " ";
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

