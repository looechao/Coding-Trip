#include<iostream>
#include<cmath>

using namespace std;

class Shape {
    public:
        virtual double calcs() = 0;  // ���麯��
};
//�̳���shape��ĳ�������
class Rectangle: public Shape {
    double width, height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
        double calcs() { return width * height; }  // ��дshape����麯��
};
//�̳���shape���������
class Trapezoid: public Shape {
    double a, b, height;
    public:
        Trapezoid(double a, double b, double h) : a(a), b(b), height(h) {}
        double calcs() { return (a + b) * height / 2.0; }  // ��дshape����麯��
};
//�̳���shape���Բ����
class Circle: public Shape {
    double radius;
    public:
        Circle(double r) : radius(r) {}
        double calcs() { return M_PI * pow(radius, 2); }  // ��дshape����麯��
};

int main() {
    Rectangle r(5, 6);
    Trapezoid t(2, 3, 4);
    Circle c(5);
    cout << "�����ε������: " << r.calcs() << endl;
    cout << "���ε������: " << t.calcs() << endl;
    cout << "Բ�ε������: " << c.calcs() << endl;

    return 0;
}
