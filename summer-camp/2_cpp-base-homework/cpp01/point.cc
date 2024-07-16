#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
    Point(){};
    Point(int ix, int iy){
        cout<<"Point()"<<endl;
        _ix = ix;
        _iy = iy;
    }
    void print(){
        cout << "(" <<_ix
         << "," <<_iy
         << ")" <<endl;
    }
    ~Point(){
        cout<<"~Point()"<<endl;
    }
private:
    int _ix;
    int _iy;
};

int main()
{
    Point pt(10,20);
    Point pt2 = pt;  //拷贝构造函数
    pt2.print();
}

