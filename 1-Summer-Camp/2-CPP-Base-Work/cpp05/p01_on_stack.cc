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
    ~Computer()
    {
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
        cout << "~computer()" << endl;
    }
    
    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

private:
    void * operator new(size_t sz){
        void * ret = malloc(sz);
        return ret;
    }

    char* _brand;
    double _price;
};


int main()
{
    Computer pc("apple", 8000);
    pc.print();
    return 0;
}

