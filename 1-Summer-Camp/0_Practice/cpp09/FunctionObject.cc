#include <iostream>
using std::cout;
using std::endl;

class FunctionObject
{
public:
    void operator()(){
        cout << "operator() function 1" << endl;
    }

    int operator()(int x){
        cout << "operator() function 2 " << x << endl;
        return x;
    }
    
    double operator()(double x, int y){
        cout << "operator() function 3 " << x << " " << y << endl;
        return x+y;
    }

};


void test0(){
    FunctionObject fo;
    fo();
    fo.operator()(); // 本质
    
    fo(5);
    fo(3.5, 7);
}

int main()
{
    test0();
    return 0;
}

