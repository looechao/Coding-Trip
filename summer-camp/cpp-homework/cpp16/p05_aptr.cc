#include <iostream>
#include <memory>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::auto_ptr;
using std::unique_ptr;

class Point{
public:
    Point(int x = 0, int y = 0)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int, int)" << endl;
    }
    
    void print( ) const{
        cout << "(" << _ix << ","
            << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};


void test0(){
    vector<unique_ptr<Point>> vec;
    unique_ptr<Point> up1(new Point(10,10));
    unique_ptr<Point> up2(new Point(20,20));
    unique_ptr<Point> up3(new Point(30,30));
    vec.push_back(std::move(up1));
    vec.push_back(std::move(up2));
    vec.push_back(std::move(up3));
    for(auto &ele : vec){
        ele->print();
    }

}

int main()
{
    test0();
    return 0;
}

