#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer{
public:
    static Computer* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Computer("Apple", 8999);
        }
        return _pInstance;
    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    void print() const{
        cout << "brand:" << _brand << endl
            << "price:" << _price << endl;
    }
    
    void init(const char * brand, double price){
        if(_brand){
            delete[] _brand;
        }
        _brand = new char[strlen(brand) + 1]();
        strcpy(_brand, brand);
        _price = price;
    }

private:
    // 析构函数私有化，不能在栈上创建
    Computer(const char* brand, double price)
    :_brand(new char[strlen(brand) + 1]())
    ,_price(price)
    {
        strcpy(_brand, brand);
    }
    ~Computer(){
        if(_brand){
            delete [] _brand;
            _brand = nullptr;
        }
        cout << "~Computer" << endl;
    }

    char* _brand;
    double _price;
    static Computer* _pInstance;
};

Computer* Computer::_pInstance = nullptr;

void test0(){
    Computer* pc0 = Computer::getInstance();
    pc0->print();
    pc0->init("huawei", 10000);
    pc0->print();
    pc0->destroy();
}

int main()
{
    test0();
    return 0;
}

