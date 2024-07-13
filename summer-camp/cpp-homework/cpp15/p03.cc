#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cout;
using std::endl;

// 添加默认参数类型
template<class T = int, int kCapacity = 10>
class Stack{
public:
    Stack()
    :_top(-1)
    ,_data(new T[kCapacity]())
    {
        cout << "Stack()" << endl;
    }

    ~Stack(){
        if(_data){
            delete[] _data;
            _data = nullptr;
        }
    }

    void push(const T& value){
        if(!full()){
            _data[++_top] = value;
        }else{
            throw std::overflow_error("Stack is full, cannot push!");
        }
    }
        
    T pop(){
        if(!empty()){
            return _data[_top--];
        }else{
            throw std::underflow_error("Stack is empty, cannot pop!");
        }
    }

    T top() const{
        if(!empty()){
            return _data[_top];
        }else{
            throw std::underflow_error("Stack is empty, no top element!");
        }
    }

    bool full() const{
        return _top == (kCapacity-1);
    }

    bool empty() const{
        return _top == -1;
    }

private:
    int _top;
    T* _data;
};


void test0(){
    try {
        Stack<string, 20> strstack;
        strstack.push("Hello");
        cout << "Top of string stack: " << strstack.top() << endl;
        strstack.pop();
        cout << "Is string stack empty? " << (strstack.empty() ? "Yes" : "No") << endl;

        Stack<char> chrstack;
        chrstack.push('A');
        cout << "Top of char stack: " << chrstack.top() << endl;
        chrstack.pop();
        cout << "Is char stack empty? " << (chrstack.empty() ? "Yes" : "No") << endl;

        Stack<> intstack;
        intstack.push(10);
        cout << "Top of int stack: " << intstack.top() << endl;
        intstack.pop();
        cout << "Is int stack empty? " << (intstack.empty() ? "Yes" : "No") << endl;
    } catch (const std::exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
}

int main()
{
    test0();
    return 0;
}

