#include <iostream>
#include <list>
#include <vector>
using std::vector;
using std::list;
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
    list<int> number(5, 3);
    display(number);
    number.push_front(100);
    display(number);
    number.push_front(200);
    display(number);
    number.pop_front();
    display(number);
    
    cout << "在list任意位置插入" << endl;
    auto it = number.begin();
    number.insert(it, 111);
    ++it;
    ++it;
    cout << * it << endl;
    number.insert(it, 30);
    display(number);

    //插入count个元素
    number.insert(it, 3, 20);
    display(number);
    
    vector<int> vec = {11, 33, 66, 44, 22};
    number.insert(it, vec.begin(), vec.end());
    display(number);
}


int main()
{
    test0();
    return 0;
}

