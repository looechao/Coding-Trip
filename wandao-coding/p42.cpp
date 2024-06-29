#include<iostream>
#include<cmath>

using namespace std;

class Base {
    public:
        virtual double calcs() = 0;  // ���麯��
};
//�̳���Base��ĳ�������
class Rectangle: public Base {
    double width, height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
        double calcs() { return width * height; }  // ��дshape����麯��
};
//�̳���Base���������
class Trapezoid: public Base {
    double a, b, height;
    public:
        Trapezoid(double a, double b, double h) : a(a), b(b), height(h) {}
        double calcs() { return (a + b) * height / 2.0; }  // ��дshape����麯��
};
//�̳���Base���Բ����
class Circle: public Base {
    double radius;
    public:
        Circle(double r) : radius(r) {}
        double calcs() { return M_PI * pow(radius, 2); }  // ��дshape����麯��
};

int main() {
    Rectangle r(6, 6);
    Trapezoid t(2, 3, 4);
    Circle c(5);
    cout << "�����ε������: " << r.calcs() << endl;
    cout << "���ε������: " << t.calcs() << endl;
    cout << "Բ�ε������: " << c.calcs() << endl;

    return 0;
}

