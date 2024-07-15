#include <iostream>
#include <deque>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

int main()
{
    size_t x = 0;
    cin >> x;
    int res = 0;
    while( x!=0 )
    {
        res += x%2;
        x /= 2;
    }
    cout << "位1的个数：" << res << endl;
    return 0;
}

