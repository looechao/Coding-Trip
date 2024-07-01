#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
    static Point & getInstance(){
        static Point pt(1,2);
        return pt;
    }

    void print() const{
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }
private:
    // 构造函数私有，不能申请栈上的空间
    Point(int x, int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int , int )" << endl;
    }
    int _ix;
    int _iy;
};

void test0(){
    Point & pt = Point::getInstance();
    pt.print();

    Point & pt2 = Point::getInstance();
    pt2.print();
    
    cout << &pt << endl;
    cout << &pt2 << endl;
}

int main()
{
    test0();
    return 0;
}

