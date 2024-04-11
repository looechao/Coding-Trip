#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    // ���캯��
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // ʹ����Ԫ���������ء�+�������
    friend Complex operator+ (const Complex &c1, const Complex &c2);

    // ��ʾ����
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex operator+ (const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(3.1, 4.2), c2(2.3, 3.4);
    Complex c3 = c1 + c2;  // ʹ�����ص� '+' �����
    c3.display();     // ������
    return 0;
}
