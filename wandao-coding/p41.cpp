#include<iostream>

using namespace std;

class Mammal{
    public:
        virtual void speak(){};  // 纯虚函数
};

//定义继承于Mammal类的Dog类

class Dog: public Mammal {
    public:
        virtual void speak(){cout<<"wolf!";}  // 纯虚函数
};


int main()
{
    Mammal m1;
    Dog d1;
    m1.speak();
    d1.speak();
}
