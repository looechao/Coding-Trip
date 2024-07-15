#include <iostream>
#include <vector>
using std::vector;
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
    cout << "sizeof(vector<int>):" << sizeof(vector<int>) << endl;
    cout << "sizeof(vector<long>):" << sizeof(vector<long>) << endl;
    vector<int> number(10, 3);
    display(number);
    number.push_back(100);
    display(number);
    number.push_back(200);
    display(number);
    number.pop_back();
    display(number);
}

int main()
{
    test0();
    return 0;
}

