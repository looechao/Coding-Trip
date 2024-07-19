#include <iostream>
#include <algorithm>
#include <vector>

using std::remove_if;
using std::cout;
using std::endl;
using std::for_each;
using std::vector;


bool func(int value)
{
    return value > 5;
}


void test0(){
    vector<int> vec{1, 3, 5, 7, 5, 1, 3, 6};
    for_each(vec.begin(), vec.end(), [](int &value){
             cout << value << " ";
             });
    cout << endl;
    
    cout << endl << endl;
    //将所有大于5的元素删除
    //函数的结果是：remove_if并不能一次将满足条件的元素删除
    //但是会返回特定删除元素的受迭代器,再配合对应的erase可以将
    //多余的元素删除
    vec.erase(remove_if(vec.begin(), vec.end(), func), vec.end());
    
    for_each(vec.begin(), vec.end(), [](int & value){
             cout << value << " ";
             });
    cout << endl;

}

int main()
{
    test0();
    return 0;
}

