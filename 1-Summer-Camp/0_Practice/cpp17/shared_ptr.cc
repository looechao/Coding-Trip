#include <iostream>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;

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
    shared_ptr<int> sp(new int(30));
    cout << "*sp = " << *sp << endl;
    cout << sp.use_count() << endl;
    shared_ptr<int> sp2(sp);
    shared_ptr<int> sp3(new int(20));
    cout << sp3.use_count() << endl;
    cout << sp.use_count() << endl;
    sp2 = sp3;
    cout << sp3.use_count() << endl;
    cout << sp.use_count() << endl;

}


void test1(){
    shared_ptr<int> sp(new int(30));
    shared_ptr<int> sp2(sp);
    shared_ptr<int> sp3(new int(20));
    vector<shared_ptr<int>> vec;
    vec.push_back(sp);
    vec.push_back(sp2); //sp的ref值是4
    vec.push_back(std::move(sp3)); //std::move 移交管理权
    vec.push_back(shared_ptr<int>(new int(50)));
    vec.push_back(std::move(sp2));

}

int main()
{
    test0();
    return 0;
}

