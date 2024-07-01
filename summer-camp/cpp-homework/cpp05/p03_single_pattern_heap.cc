#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
    static Point* getInstance(){
        if(pt == nullptr){
            pt = new Point(2,3);
        }
        return pt;
    }

    static void destroy(){
        if(pt){
            delete pt;
            pt = nullptr;
        }
        cout << "deleted from heap" << endl;
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
    // 定义一个指针保存第一次创建的对象
    static Point* pt;
};

Point* Point::pt = nullptr;




void test0(){
    Point* pt1 = Point::getInstance();
    pt1->print();
    pt1->destroy();
}

int main()
{
    test0();
    return 0;
}

