#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Point{
public:
    Point(int x, int y)
    :_ix(x)
    ,_iy(y)
    {}
    
    Point()
    :_ix(0)
    ,_iy(0)
    {}


    Point(const Point& pt)
    {
        _ix = pt._ix;
        _iy = pt._iy;
    }
    
    void print(){
        cout << "(" << _ix << "," 
            << _iy << ")" << endl;
    }
    ~Point(){
        cout << "~Point" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test0(){
    vector<Point> points;
    cout << "is points empty ? " << points.empty() << endl;
}

void test1(){
    vector<Point> points(10);
    
    Point pt(5,6);
    vector<Point>  points2(10,pt);
    for(auto & ele : points2){
        ele.print();
    }
}

int main()
{
    test1();
    return 0;
}

