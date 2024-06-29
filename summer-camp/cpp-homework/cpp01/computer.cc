#include <iostream>

Computer{
public:
    Computer(const char* brand, double price)
    :
private:
    char* _brand;
    double _price;
};


void test0(){
    Computer pc("Apple", 2000);
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

