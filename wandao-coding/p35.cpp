#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    // 构造函数
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 使用友元函数来重载‘+’运算符
    friend Complex operator+ (const Complex &c1, const Complex &c2);

    // 显示复数
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex operator+ (const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(3.1, 4.2), c2(2.3, 3.4);
    Complex c3 = c1 + c2;  // 使用重载的 '+' 运算符
    c3.display();     // 输出结果
    return 0;
}
