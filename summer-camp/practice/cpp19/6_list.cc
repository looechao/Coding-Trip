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
    
    number.sort(CompareList());
    display(number);
}

int main()
{
    test0();
    return 0;
}

