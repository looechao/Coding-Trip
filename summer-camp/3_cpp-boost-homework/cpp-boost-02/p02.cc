#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::vector;
using std::list;
using std::deque;
using std::cout;
using std::endl;

template <typename Container>

void display(const Container& con){
    for(auto &ele : con)
    {
        cout << ele << " ";
    }
    cout << endl;
}


void test0(){
    //无参构造
    vector<int> vec1;
    display(vec1);
    
    //多个相同的值
    vector<int> vec2(10,3);
    display(vec2);

    //使用迭代器范围
    vector<int> vec3(vec2.begin(), vec2.end());
    display(vec3);

    //使用大括号
    vector<int> vec4{1,2,3,4,5,6};
    display(vec4);

    //使用拷贝构造
    vector<int> vec5(vec4);
    display(vec5);

    //使用移动构造
    vector<int> vec6(std::move(vec5));
    display(vec6);
}

void test1(){
    //无参构造
    deque<int> deq1;
    display(deq1);
    
    //多个相同的值
    deque<int> deq2(10,3);
    display(deq2);

    //使用迭代器范围
    deque<int> deq3(deq2.begin(), deq2.end());
    display(deq3);

    //使用大括号
    deque<int> deq4{1,2,3,4,5,6};
    display(deq4);

    //使用拷贝构造
    deque<int> deq5(deq4);
    display(deq5);

    //使用移动构造
    deque<int> deq6(std::move(deq5));
    display(deq6);
}



void test2(){
    //无参构造
    list<int> lst1;
    display(lst1);
    
    //多个相同的值
    list<int> lst2(10,3);
    display(lst2);

    //使用迭代器范围
    list<int> lst3(lst2.begin(), lst2.end());
    display(lst3);

    //使用大括号
    list<int> lst4{1,2,3,4,5,6};
    display(lst4);

    //使用拷贝构造
    list<int> lst5(lst4);
    display(lst5);

    //使用移动构造
    list<int> lst6(std::move(lst5));
    display(lst6);
}


int main()
{
    test2();
    return 0;
}

