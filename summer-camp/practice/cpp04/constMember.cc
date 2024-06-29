#include <iostream>

class Point{
public:
    Point(int x, int y)
    : 
private:
    // C++ 也允许了在声明时直接进行初始化
    // 属于默认值的性质
    const int _ix = 1;
    const int _iy = 1;
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

