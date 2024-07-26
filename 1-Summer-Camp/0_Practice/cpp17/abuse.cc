#include <iostream>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;
using std::unique_ptr;


class Point{
public:
    Point(int x, int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int, int)" << endl;
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
    // double free问题
    unique_ptr<Point> up(new Point(1,2));
    unique_ptr<Point> up2(new Point(1,2));
    up->print();
    up2->print();
    cout << up.get() << endl;
    cout << up2.get() << endl;
}

void test1(){
    Point* pt = new Point(10,20);
    shared_ptr<Point> sp(pt);
    shared_ptr<Point> sp2(pt);
    sp->print();
    sp2->print();
    cout << sp.get() << endl;
    cout << sp2.get() << endl;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
}

void test2(){
    Point* pt = new Point(10,20);
    shared_ptr<Point> sp(pt);
    shared_ptr<Point> sp2(sp);
    sp->print();
    sp2->print();
    cout << sp.get() << endl;
    cout << sp2.get() << endl;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
}

int main()
{
    test2();
    return 0;
}

