#include<iostream>
#include<math.h>
#include<cstring>

using namespace std;

class Box{
private:
    int length;  //��
    int width;  //��
    int height; //��
public:
    // ��Ӵ������Ĺ��캯��
    Box(int length, int width, int height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    int calcv()   //�������
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
    cout<<"�����"<<b1.calcs()<<endl;
    cout<<"�����"<<b1.calcv();
    return 0;
}
