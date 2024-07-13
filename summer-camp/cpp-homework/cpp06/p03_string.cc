#include <iostream>
using std::cout;
using std::endl;

class String{
public:
    String()
    {
        _pstr = new char[1];
        *_pstr = '\0';
    }
    
    String(const char* pstr)
    {
        int length = 0;
        const char* start = pstr;
        while(*pstr != '\0'){
            length ++;
            pstr++;
        }
        
        _pstr = new char[length+1];
        for(int i = 0; i < length; i++){
            _pstr[i] = start[i];
        }

    }

    String(const String &rhs)
    :_pstr(rhs._pstr)
    {}

    String &operator = (const String &rhs)
    {
        _pstr = rhs._pstr;
        return *this;
    }

    ~String(){
        cout << "~String" << endl;
    }
    void print(){
        while(*_pstr != '\0'){
            cout << *_pstr;
            _pstr++;
        }
        cout<<endl;
    }
private:
    char* _pstr;
};


void test0(){
    String str;
    str.print();
}

void test1(){
    String str2 = "Hello, world";
    String str3("wangdao");
    String str4 = str3;
    str2.print();
    str3.print();
    str4.print();
}


int main()
{
    test1();
    return 0;
}

