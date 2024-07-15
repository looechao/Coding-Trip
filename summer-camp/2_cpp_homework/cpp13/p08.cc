#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Figure{
public:
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
};

class Rectangle : public Figure{
public:
    Rectangle(double w, double h)
    :_width(w)
    ,_height(h)
    {}

    string getName() const override{
        return "长方形";
    }

    double getArea() const override{
        return _width * _height;
    }
private:
    double _width;
    double _height;
};

class Circle : public Figure{
public:
    Circle(double r) 
    : _radius(r)
    {}

    string getName() const override{
        return "圆形";
    }
    double getArea() const override{
        return 3.14159 * (_radius * _radius);
    }
private:
    double _radius;
};

class Triangle : public Figure{
public:
    Triangle(double a, double b, double c)
    :_side1(a)
    ,_side2(b)
    ,_side3(c)
    {}

    string getName() const override{
        return "三角形";
    }
    double getArea() const override{
        //使用海伦公式计算三角形面积
        double s = (_side1 + _side2 + _side3) / 2;
        return sqrt(s * (s - _side1) * (s - _side2 ) * (s - _side3));
    }

private:
    double _side1;
    double _side2;
    double _side3;
};

void display(Figure & fig){
    cout << fig.getName()
        << "的面积是:"
        << fig.getArea() << endl;
}

void test(){
    Rectangle r(10, 20);
    Circle c(15);
    Triangle t(3, 4, 5);
    display(r);
    display(c);
    display(t);
}


int main(){
    test();
    return 0;
}
