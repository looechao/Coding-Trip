#include<iostream>
#include<math.h>

using namespace std;

class Triangle{
private:
    int a;
    int b;
    int c;
public:
    Triangle(int aa = 0, int bb = 0, int cc = 0) : a(aa), b(bb), c(cc) {}
    double calcs()
    {
        double s=(a+b+c)/2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    friend double operator+(Triangle &t1, Triangle &t2);
};

double operator+ (Triangle &t1, Triangle &t2) {
    return t1.calcs() + t2.calcs();
}


int main()
{
    Triangle t1(3,4,5);
    Triangle t2(6,8,10);
    double totalArea = t1 + t2;
    cout<<"两三角形的面积之和："<<totalArea<<endl;
}
