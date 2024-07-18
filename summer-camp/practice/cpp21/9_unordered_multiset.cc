#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::unordered_multiset;
using std::vector;
using std::pair;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
    }

    int getX() const
    {
        return _ix;
    }

    int getY() const
    {
        return _iy;
    }

    ~Point()
    {

    }

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix
       << ", " << rhs._iy
       << ")";

    return os;
}

namespace  std
{
template <>
struct hash<Point>
{
    size_t operator()(const Point &rhs) const
    {
        return (rhs.getX() >> 2) ^ (rhs.getY() >> 4);
    }
};//end of struct hash

}//end of namespace std

namespace  std
{
template <>
struct equal_to<Point>
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        return (lhs.getX() == rhs.getX()) &&
            (lhs.getY() == rhs.getY());
    }
};

}//end of namespace std

void test()
{
    unordered_multiset<Point>  number = {
        Point(1, 2),
        Point(-1, 2),
        Point(1, -2),
        Point(2, 2),
        Point(1, 2),
        Point(3, 2),
    };
    display(number);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}


