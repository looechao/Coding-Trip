#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::vector;
using std::for_each;
using std::cout;
using std::endl;
using std::ostream_iterator;


void func(int& value)
{
    ++value;
    cout << value << " ";
}

void test0(){
    vector<int> vec = {1, 4, 7, 9, 5, 2};
    /* for_each(vec.begin(), vec.end(), func); */
    //匿名函数
    for_each(vec.begin(), vec.end(), [](int &value){
        ++value;
        cout << value << " ";
    });
    cout << endl;
    
    copy(vec.begin(), vec.end(),
         ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

