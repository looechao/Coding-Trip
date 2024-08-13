#include <iostream>
#include <vector>
#include <deque>
using std::vector;
using std::deque;
using std::cout;
using std::endl;


template <typename Container>

void display(const Container& con){
    cout << "size = " << con.size() << endl; 
    for(auto &ele : con)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void test0(){
    deque<int> number(10, 3);
    cout << "在list任意位置插入" << endl;
    auto it = number.begin();
    number.insert(it, 111);
    ++it;
    ++it;
    cout << "*it = " << * it << endl;
    number.insert(it, 30);
    display(number);

    cout << "*it = " << * it << endl;
    //插入count个元素
    number.insert(it, 3, 20);
    display(number);
    
    vector<int> vec = {11, 33, 66, 44, 22};
    cout << "*it = " << * it << endl;
    number.insert(it, vec.begin(), vec.end());
    display(number);
    cout << "*it = " << * it << endl;
    number.insert(it, {1, 2, 3, 4 ,5 ,6 ,7 ,9});
    display(number);
    
    number.clear();
    number.shrink_to_fit();
    display(number);
}

int main()
{
    test0();
    return 0;
}

