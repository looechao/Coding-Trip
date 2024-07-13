#include <iostream>
#include <string.h>
#define MAX_SIZE 1024
using std::cout;
using std::endl;
using std::cin;

class String 
{
public:
	
    String()
    {
        _pstr = new char[1];
        *_pstr = '\0';
    }
	
    String(const char *pstr)
    {
        int length = 0;
        const char* start = pstr;
        while(*pstr != '\0'){
            length++;
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

    ~String(){
        if(!_pstr){
            delete [] _pstr;
            _pstr = nullptr;
        }
    }


    String& operator=(const String &rhs){
        _pstr = rhs._pstr;
        return *this;
    }

	String &operator=(const char *pstr)
    {
        int length = 0;
        const char* start = pstr;
        while(*pstr != '\0'){
            length++;
            pstr++;
        }
        _pstr = new char[length+1];
        for(int i = 0; i < length; i++){
            _pstr[i] = start[i];
        }
        return *this;
    }

    void print(){
        while(*_pstr != '\0'){
            cout << *_pstr;
            _pstr++;
        }
        cout<<endl;
    }




	String &operator+=(const String &rhs)
    {
        int length = strlen(_pstr) + strlen(rhs._pstr);
        char* full = new char[length+1];
        strcpy(full, _pstr);
        strcpy(&full[strlen(_pstr)], rhs._pstr);
        _pstr = full;
        return *this;
    }

	String &operator+=(const char* pstr)
    {
        int length = strlen(_pstr) + strlen(pstr);                                                                                              
        char* full = new char[length+1];
        strcpy(full, _pstr);
        strcpy(&full[strlen(_pstr)], pstr);
        delete []_pstr;
        _pstr = full;
        return *this;
    }
	
	char &operator[](std::size_t index)
    {
        return _pstr[index];
    }

    const char &operator[](std::size_t index)const{
        return _pstr[index];
    }
    
    std::size_t size() const{
        return strlen(_pstr);
    }


    const char* c_str() const{
        cout << _pstr;
        return _pstr;
    }
	
	friend bool operator==(const String &lhs, const String &rhs);
	
    friend bool operator!=(const String &lhs, const String &rhs);
	
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);
	
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char * _pstr;
};


bool operator==(const String & lhs, const String &rhs){
    return (strcmp(lhs._pstr, rhs._pstr) == 0);
}

bool operator!=(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr, rhs._pstr) != 0);
}

bool operator<(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr, rhs._pstr) < 0);
}


bool operator>(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr, rhs._pstr) > 0);
}


bool operator<=(const String &lhs, const String &rhs){
    return !(lhs > rhs);
}


bool operator>=(const String &lhs, const String &rhs){
    return !(lhs<rhs);
}


std::ostream &operator<<(std::ostream &os, const String &s)
{
    os<< s._pstr;
    return os;
}


std::istream &operator>>(std::istream &is, String &s){
    char* tmp = new char[MAX_SIZE];
    is >> tmp;
    delete [] s._pstr;
    s._pstr = tmp;
    return is;
}


String operator+(const String &lhs, const String &rhs)
{
    String result(lhs);
    result += rhs;
    return result;
}

String operator+(const String &lhs, const char *rhs)
{
    String result(lhs);
    result += rhs;
    return result;
}

String operator+(const char *lhs, const String &rhs){
    String result(lhs);
    result += rhs;
    return result;
}




void test0(){
    char test[] = "asdfsdg";
    String str = test;
    str.print();
}

void test1(){
    String str1("hello");
    String str2(str1);
    str2.print();
}

void test2(){
    String str1("hello");
    String str2(",world");
    str1 += str2;
    str1.print();
}

void test3(){
    String str1("hello"); 
    char a[] = ",world";
    str1 += a;
    str1.print();
}


void test4(){
    String str1("hello"); 
    cout<<str1[0];
}

void test5(){
    String str1("hello"); 
    cout<<str1[0];
}

void test6(){
    String str1 = "adsdf";
    cout<< "str1.size() = " <<str1.size()<<endl;
    cout<< str1.c_str() << endl;
    cin>>str1;
    cout<<str1<<endl;
}

void test7(){
    String str1("hello"); 
    char a[] = ",world";
    String str2 = str1 + str1;
    String str3 = a + str1;
    String str4 = str1 + a;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
}




int main()
{
    test7();
    return 0;
}

