#include <iostream>
using std::cout;
using std::endl;


class Rectangle{
public:
    Rectangle(double w, double h)
    :_width(w)
    ,_height(h)
    {}

    double area() const{
        return _width*_height;
    }

    double getWidth(){
        return _width;
    }
    
    double getHeight(){
        return _height;
    }
protected:
    int _width;
    int _height;
};

class RectangleGUI : public Rectangle{
public:
    RectangleGUI(double w, double h)
    :Rectangle(w,h){}

    void draw() {
        cout << "rectangle's" << "width:" << getWidth() << endl
            << "rectangle's" << "height:" << getHeight() << endl;
    }
};


void test0(){
    Rectangle rect(10,5);
    cout << "area: " << rect.area() << endl;
    RectangleGUI rectdraw(10,5);
    rectdraw.draw();
}

int main()
{
    test0();
    return 0;
}

