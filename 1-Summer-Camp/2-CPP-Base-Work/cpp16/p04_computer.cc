#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public:

    Computer(int price, const char* brand)
    :_price(price)
    {
        _brand = new char[strlen(brand) + 1];
        strcpy(_brand, brand);
        cout << "Computer(int, char*)" << endl;
    }

    ~Computer(){
        cout << "~Computer()" << endl;
        if(_brand){
            delete _brand;
            _brand = nullptr;
        }
    }

    int getPrice() const{
        return _price;
    }

    char* getBrand() const{
        return _brand;
    }

    Computer(const Computer& rhs) = delete;
    Computer& operator=(const Computer& rhs) = delete;

private:
    int _price; 
    char* _brand;
};


void test0(){
    Computer* comp = new Computer(5000, "lenovo");
    cout << comp->getBrand()<< " ";
    cout << comp->getPrice();
    cout << endl;
    delete comp;
}

int main()
{
    test0();
    return 0;
}

