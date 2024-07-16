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
    vector<int> vec1{1,2,3,4};
    vector<int> vec2{1,2,3};
    deque<int>  deq1{4,5,6,7};
    deque<int>  deq2{44,5,6};
    list<int> lst1{1, 3, 4, 5, 6};
    list<int> lst2{1, 9, 4, 5, 6};
    if(lst1 < lst2){
        cout << "good " << endl;
    }
}


int main()
{
    test0();
    return 0;
}

