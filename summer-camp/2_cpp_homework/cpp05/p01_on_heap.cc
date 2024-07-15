#include <iostream>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;


class Computer
{
public:

    Computer(const char * brand, double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand, brand);
    }
    
    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
private:
    
    ~Computer()
    {
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
        cout << "~computer()" << endl;
    }
    
    char* _brand;
    double _price;
};


int main()
{
    Computer* pc = new Computer("apple", 8000);
    pc->print();
    return 0;
}

