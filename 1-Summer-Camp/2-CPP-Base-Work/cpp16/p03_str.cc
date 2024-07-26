#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class String{
public:
    String()
    :_pstr(new char[1]())
    {
        cout << "String()" << endl;
    }
    
    String(const char* pstr)
    :_pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char*)" << endl;
        strcpy(_pstr, pstr);
    }
    
    String(const String & rhs)
    :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String & operator=(String && rhs){
        if(this != &rhs){
            delete [] _pstr;
            //浅拷贝
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
            cout << "String& operator=(String&&)" << endl;
        }
        return *this;
    }

    size_t length() const
    {
        size_t len = 0;
        if(_pstr)
        {
            len = strlen(_pstr);
        }

        return len;

    }

    const char * c_str() const
    {
        if(_pstr)
        {
            return _pstr;
        }
        else
        {
            return nullptr;
        }
    }

    void print() const
    {
        if(_pstr)
        {
            cout << "_pstr = " << _pstr << endl;
        }else{
            cout << endl;
        }
    }    


    String(String && rhs)
    :_pstr(rhs._pstr)
    {
        cout << "String(String&&)" << endl;
        rhs._pstr = nullptr;
    }
    
    ~String()
    {
        cout << "~String()" << endl;
        if(_pstr)
        {
            delete []_pstr;
            _pstr = nullptr;
        }
    }

private:
    char* _pstr;
};

void test0(){
    String s1;
    s1 = "asdfasf";
    String s3(std::move(s1));
}

int main()
{
    test0();
    return 0;
}

