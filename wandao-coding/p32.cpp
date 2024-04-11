#include<iostream>
#include<math.h>
#include<cstring>

using namespace std;

class Box{
private:
    int length;  //长
    int width;  //宽
    int height; //高
public:
    // 添加带参数的构造函数
    Box(int length, int width, int height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    int calcv()   //计算体积
    {
        return width*length*height;
    }
    int calcs()    //
    {
        return length*width*2+length*height*2+width*height*2;
    }
};


int main()
{
    Box b1(10,20,30);
    cout<<"面积是"<<b1.calcs()<<endl;
    cout<<"体积是"<<b1.calcv();
    return 0;
}
