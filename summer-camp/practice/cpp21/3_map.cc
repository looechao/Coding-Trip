#include <iostream>
#include <map>
#include <string>
#include <math.h>
using std::pair;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::make_pair;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    :_ix(ix)
    ,_iy(iy)
    {}

    float getDistance() const{
        return hypot(_ix, _iy);
    }

    int getX() const
    {
        return _ix;
    }

    int getY() const
    {
        return _iy;
    }


    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix << ", " << rhs._iy << ")";
    return os;
}


template <typename Container>
void display(const Container &con)
{
    for(auto &ele: con)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}

void test0(){
    map<string, Point> num = {
        {"wangdao", Point(1, 2)},
        {"hubei", Point(-1, 2)},
        pair<string, Point>("hubei", Point(-1, 2)),
        pair<string, Point>("wuhan", Point(-1, 2)),
        make_pair("beijing", Point(2, 4)),
        make_pair("beijing", Point(2, 4)),
    };
    display(num);
}


int main()
{
    test0();
    return 0;
}

