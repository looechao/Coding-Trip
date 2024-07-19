#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::vector;
using std::cout;
using std::endl;

template<typename Container>

void display(const Container& C){
    for(auto &ele: C)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void test0(){
    vector<int> vec;
    vec.reserve(10);
    cout << "111" << endl;
    istream_iterator<int> isi(std::cin);
    cout << "222" << endl;
    copy(isi, istream_iterator<int>(), vec.begin());
    cout << "333" << endl;
    
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << "444" << endl;
    cout << endl;
}


void test1(){
    vector<int> vec;
    vec.reserve(10);
    istream_iterator<int> isi(std::cin);
    copy(isi, istream_iterator<int>(), std::back_inserter(vec));
    
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    test1();
    return 0;
}

