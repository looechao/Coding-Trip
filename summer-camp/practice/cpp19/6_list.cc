#include <iostream>
#include <list>
using std::list;
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

struct CompareList{
    bool operator() (const int &lhs, const int &rhs) const
    {
        cout << "Struct CompareList" << endl;
        return lhs < rhs;
    }
};


void test0(){
    list<int> number = {1, 3, 5, 7, 5, 5, 3, 8};
    display(number);

    number.reverse();
    display(number);

    /* number.sort(); */
    cout << "=======" << endl;
    std::less<int> lst;
    number.sort(lst);
    display(number);
    cout << "=======" << endl;
    number.sort(std::greater<int> ());
    
    /* number.sort(CompareList()); */
    /* display(number); */

    number.unique();
    display(number);

    list<int> other = {11, 55, 44 ,33, 22, 6};
    other.sort(std::less<int> ());
    display(other);
    cout << "merge list : "<< endl;
    number.merge(other);
    number.sort(std::less<int> ());
    display(number);
    display(other);
}

void test1(){
    list<int> number = {1, 3, 5, 9, 8};
    display(number);

    list<int> other = {11, 44, 77, 99, 33, 22};
    auto it = number.begin();
    ++it;
    ++it;
    cout << "*it = "<< *it << endl; 
    
    // 移动整个链表到目标链表
    /* number.splice(it, other); */
    /* display(number); */
    /* display(other); */

    // 移动另外链表中的某个元素到目标链表
    auto it2 = --other.end();
    number.splice(it, other, it2);
    display(number);
    display(other);
      
    auto it3 = other.begin();
    cout << "*it3 = " << *it3 << endl << endl << endl;
    it2 = --other.end();
    cout << "*it2 = " << *it2 << endl;
    number.splice(it, other, it3, it2);
    display(number);
    display(other);
}

void test2(){
    list<int> num{1, 3, 22, 11, 44, 77, 99, 5, 9, 8};
    display(num);
    //在同一个链表中进行splice操作
    auto it = num.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    auto it2 = --num.end();
    --it2;
    cout << "*it2 = " << *it2 << endl;
    num.splice(it, num, it2);
    display(num);
}

int main()
{
    test2();
    return 0;
}

