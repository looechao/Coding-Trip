#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Point{
public:
    Point(int x = 0, int y = 0)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int x = 0, int y = 0)" << endl;
    }
    
    Point(const Point &rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout << "Point(&rhs)" << endl;
    }


private:
    int _ix;
    int _iy;
};

void test0(){
    vector<Point> vec;
    cout << "push_back:" << endl;
    vec.push_back( Point(1,2));
}

int main()
{
    test0();
    return 0;
}

