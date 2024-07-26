#include <iostream>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;
using std::unique_ptr;


class Point
: public std::enable_shared_from_this<Point>
{
public: 
    Point(int x, int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int, int)" << endl;
    }

    /* Point* addPoint(Point* pt){ */
    /*     _ix += pt->_ix; */
    /*     _iy += pt->_iy; */
    /*     return this; */
    /* } */


    /* shared_ptr<Point> addPoint(Point * pt){ */
    /*     _ix += pt->_ix; */
    /*     _iy += pt->_iy; */
    /*     //return 语句中创建的shared_ptr对象依然与sp共用了裸指针 */
    /*     return shared_ptr<Point>(this); */
    /* } */

    /* shared_ptr<Point> addPoint(Point * pt){ */
    /*     _ix += pt->_ix; */
    /*     _iy += pt->_iy; */
    /*     //return 语句中创建的shared_ptr对象依然与sp共用了裸指针 */
        
    /*     //利用sp管理的point对象创建出一个新的Point资源 */
    /*     //交给新的智能指针进行管理 */
    /*     return shared_ptr<Point>(new Point(_ix, _iy)); */
    /* } */

    //3.
    shared_ptr<Point> addPoint(Point* pt){
        _ix += pt->_ix;
        _iy += pt->_iy;
        //返回一个共享this的shared_ptr对象
        return shared_from_this();
    }

    void print(){
        cout << "(" << _ix << ","
            << _iy << ")" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test0(){
    shared_ptr<Point> sp(new Point(1,2));
    shared_ptr<Point> sp2(new Point(3,4));
    
    //这种情况实际上是sp3与sp共用了一个裸指针进行创建
    /* sp->addPoint(sp2.get()); */
    shared_ptr<Point> sp3(sp->addPoint(sp2.get()));

    cout << sp3.use_count() << endl;

    sp3->print();
}

int main()
{
    test0();
    return 0;
}

