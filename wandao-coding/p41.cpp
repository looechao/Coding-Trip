#include<iostream>

using namespace std;

class Mammal{
    public:
        virtual void speak(){};  // ���麯��
};

//����̳���Mammal���Dog��

class Dog: public Mammal {
    public:
        virtual void speak(){cout<<"wolf!";}  // ���麯��
};


int main()
{
    Mammal m1;
    Dog d1;
    m1.speak();
    d1.speak();
}
