#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
    static Singleton * getInstance(){
        pthread_once(&_once, init_r);
        return _pInstance;
    }

    void func(){
        cout << "func()" << endl;
    }

    void init(int x, int y){
        _ix = x;
        _iy = y;
    }

    void print() const{
        cout << "(" << this->_ix
        << "," << this->_iy
        << ")" << endl;
    }

private:
    static void init_r(){
        _pInstance = new Singleton(1,2);
        atexit(destroy);
    }

    static void destroy(){
        delete _pInstance;
        _pInstance = nullptr;
        cout << ">> delete heap" << endl;
    }

    Singleton(const Singleton &rhs) = delete;
    Singleton & operator=(const Singleton &rhs) = delete;
    Singleton(int x, int y = 0)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Singleton(int, int)" << endl;
    }
    ~Singleton(){
        cout << "~Singleton()" << endl;
    }
private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
    static pthread_once_t _once;
};
Singleton * Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;


void test0(){
    Singleton::getInstance()->init(7,8);
    Singleton::getInstance()->print();
    Singleton::getInstance()->func();
}

int main()
{
    test0();
    return 0;
}

