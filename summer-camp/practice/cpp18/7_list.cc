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


void test0(){
    list<int> number(10, 3);
    display(number);
    number.push_front(100);
    display(number);
    number.push_front(200);
    display(number);
    number.pop_front();
    display(number);
}

int main()
{
    test0();
    return 0;
}

