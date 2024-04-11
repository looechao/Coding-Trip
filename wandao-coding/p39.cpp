#include<iostream>
#include<cmath>

using namespace std;

class Shape {
    public:
        virtual double calcs() = 0;  // 纯虚函数
};
//继承于shape类的长方形类
class Rectangle: public Shape {
    double width, height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
        double calcs() { return width * height; }  // 重写shape类的虚函数
};
//继承于shape类的梯形类
class Trapezoid: public Shape {
    double a, b, height;
    public:
        Trapezoid(double a, double b, double h) : a(a), b(b), height(h) {}
        double calcs() { return (a + b) * height / 2.0; }  // 重写shape类的虚函数
};
//继承于shape类的圆形类
class Circle: public Shape {
    double radius;
    public:
        Circle(double r) : radius(r) {}
        double calcs() { return M_PI * pow(radius, 2); }  // 重写shape类的虚函数
};

int main() {
    Rectangle r(5, 6);
    Trapezoid t(2, 3, 4);
    Circle c(5);
    cout << "长方形的面积是: " << r.calcs() << endl;
    cout << "梯形的面积是: " << t.calcs() << endl;
    cout << "圆形的面积是: " << c.calcs() << endl;

    return 0;
}
