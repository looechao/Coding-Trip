#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point{
public:
    Point(float x, float y)
    :_x(x)
    ,_y(y)
    {}

    Point(const Point& rhs){
        _x = rhs._x;
        _y = rhs._y;
    }

    Point& operator=(const Point& rhs){
        _x = rhs._x;
        _y = rhs._y;
        return *this;
    }

    float getX() const{
        return _x;
    }

    float getY() const{
        return _y;
    }

    friend class Line;

private:
    float _x;
    float _y;
};


class Color{
public:
    Color(const string& color)
    :_color(color)
    {}
    
    Color(const Color& rhs){
        _color = rhs._color;
    }

    Color& operator=(const Color& rhs){
        _color = rhs._color;
        return *this;
    }

    string getColor() const{
        return _color;
    }


private:
    string _color;
};


class Line{
public:
    Line(const Point& start, const Point& end)
    :_start(start)
    ,_end(end)
    {}
    
    Line(int x1, int y1, int x2, int y2)
    :_start(x1, y1)
    ,_end(x2, y2)
    {}

    Line(const Line& rhs)
    :_start(0,0)
    ,_end(0,0)
    {
        _start = rhs._start;
        _end = rhs._end;
    }

    float getLength() const{
        float dx = _start.getX() - _end.getX();
        float dy = _start.getY() - _end.getY();
        return sqrt(dx*dx + dy*dy);
    }

    Point& getStartPoint(){
        return _start;
    }
    Point& getEndPoint(){
        return _end;
    }
private:
    Point _start;
    Point _end;
};


class Triangle : public Line, public Color{
public:
    Triangle(const Point& start, const Point& end, float height, const string& color)
    :Line(start, end)
    ,Color(color)
    ,_height(height)
    {}

    float getArea() {
        return 0.5 * Line::getLength() * _height; 
    }

    float getPerimeter() {
        float baseLength = Line::getLength();
        float legLength = _height;
        float hypotenuse = sqrt(baseLength*baseLength + legLength * legLength);
        return baseLength + legLength + hypotenuse;
    }

private:    
    float _height;
};




int main(){
    string color = "red";
    Point start(0.0, 0.0);
    Point end(0.0, 3.0);
    float height = 4.0;
    Triangle triangle(start, end, height, color);

    cout << "三角形的颜色:" << triangle.Color::getColor() << endl;
    cout << "三角形的面积:" << triangle.getArea() << endl;
    cout << "三角形的周长:" << triangle.getPerimeter() << endl;
    return 0;
}




