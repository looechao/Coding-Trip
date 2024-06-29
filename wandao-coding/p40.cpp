#include<iostream>
using namespace std;

class Counter {
    private:
        int count; // 计数器值
    public:
        Counter() : count(0) {} // 构造函数，初始化计数器为0
        void increment() { count++; } // 增加计数
        void decrement() { if(count > 0) count--; } // 减少计数，但不会小于0
        int get_count() const { return count; } // 返回当前计数
};

int main() {
    Counter c;
    c.increment();
    c.increment();
    cout << "Count: " << c.get_count() << endl; // 输出 "Count: 2"
    c.decrement();
    cout << "Count: " << c.get_count() << endl; // 输出 "Count: 1"
    return 0;
}
