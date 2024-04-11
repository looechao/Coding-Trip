#include<iostream>
#include<cmath>

using namespace std;

class Base {
    public:
        virtual double calcs() = 0;  // 纯虚函数
};
//继承于Base类的长方形类
class Rectangle: public Base {
    double width, height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
        double calcs() { return width * height; }  // 重写shape类的虚函数
};
//继承于Base类的梯形类
class Trapezoid: public Base {
    double a, b, height;
    public:
        Trapezoid(double a, double b, double h) : a(a), b(b), height(h) {}
        double calcs() { return (a + b) * height / 2.0; }  // 重写shape类的虚函数
};
//继承于Base类的圆形类
class Circle: public Base {
    double radius;
    public:
        Circle(double r) : radius(r) {}
        double calcs() { return M_PI * pow(radius, 2); }  // 重写shape类的虚函数
};

int main() {
    Rectangle r(6, 6);
    Trapezoid t(2, 3, 4);
    Circle c(5);
    cout << "长方形的面积是: " << r.calcs() << endl;
    cout << "梯形的面积是: " << t.calcs() << endl;
    cout << "圆形的面积是: " << c.calcs() << endl;

    return 0;
}

