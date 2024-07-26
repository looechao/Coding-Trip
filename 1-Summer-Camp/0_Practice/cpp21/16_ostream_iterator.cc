#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::vector;
using std::ostream_iterator;
using std::cout;
using std::endl;
using std::copy;

void test0(){
    vector<int> vec = {1, 5, 9, 7, 4};
    ostream_iterator<int> osi(cout, " ");
    copy(vec.begin(), vec.end(), osi);
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

