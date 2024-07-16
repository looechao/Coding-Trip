#include <iostream>
#include <string.h>

using namespace std;

class String {
public:
    String(const char * pstr)
    :_size(strlen(pstr))
    {
        if(strlen(pstr) < sizeof(_buffer._local)){
            strcpy(_buffer._local, pstr);
            _capacity = sizeof(_buffer._local);
        }else{
            _buffer._pointer = new char[strlen(pstr)+1];
            strcpy(_buffer._pointer, pstr);
            _capacity = _size+1;
        }
    }

    ~String(){
        if(_capacity > sizeof(_buffer._local)){
            if(_buffer._pointer){
                delete [] _buffer._pointer;
            }
            _buffer._pointer = nullptr;
        }
    }

    char & operator[](size_t idx){
        if(idx < _size){
            if(_size < sizeof(_buffer._local)){
                return _buffer._local[idx];
            }else{
                return _buffer._pointer[idx];
            }
        }else{
            static char a = '\0';
            cout << "error" << endl;
            return a;
        }
    };

    friend
        ostream & operator << (ostream & os,const String & rhs){
            if(rhs._size < sizeof(_buffer._local)){
                os << rhs._buffer._local;
            }else{
                os << rhs._buffer._pointer;
            }
            return os;
        }
private:
	union Buffer{
		char * _pointer = nullptr;
		char _local[16];
	};
	
	size_t _size;
	size_t _capacity;
    Buffer _buffer;
};

int main(){
    String str1("hello");
    String str2("hello,world!!!!!");
    cout << str1 << endl;
    cout << str2 << endl;
    cout << &str1 << endl;
    printf("%p\n", &str1[0]);
    cout << &str2 << endl;
    printf("%p\n", &str2[0]);

}
