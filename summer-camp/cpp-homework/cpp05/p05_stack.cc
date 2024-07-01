#include <iostream>
using std::cout;
using std::endl;


class Stack{
public:
    Stack(int size)
    :_topIdx(-1)
    ,_capacity(size)
    {
        _data = new int[_capacity];
    }

    ~Stack(){
        if(_data){
            delete _data;
            _data = nullptr;
        }
        cout << "~Stack" << endl; 
    }

    bool empty(){
        return _topIdx == -1;
    }

    bool full(){
        return _topIdx == _capacity - 1;
    }

    void push(int val){
        if(!full()){
            _data[++_topIdx] = val;
        }else{
            cout << "push failed! stack is full!" << endl;
        }
    }

    void pop(){
        if(!empty()){
            --_topIdx;
        }else{
            cout << "pop failed! stack is empty!" << endl;
        }
    }
    
    int top(){
        if(!empty()){
            return _data[_topIdx];
        }else{
            cout << "peek failed! the stack is empty!" << endl;
        }
    }

private:
    int* _data;
    int _topIdx;
    int _capacity;
};


void test0(){
    Stack s1 = Stack(5);
    cout << "stack is empty?" << s1.empty() << endl;
    s1.push(1);
    cout << "top is " << s1.top() << endl;
    s1.push(2);
    cout << "top is " << s1.top() << endl;
    s1.push(3);
    cout << "top is " << s1.top() << endl;
    s1.push(4);
    cout << "top is " << s1.top() << endl;
    s1.push(5);
    cout << "top is " << s1.top() << endl;
    cout << "stack is full?" << s1.full() << endl;
    s1.push(6);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout << "stack is empty?" << s1.empty() << endl;
}

int main()
{
    test0();
    return 0;
}

