#include<iostream>
using namespace std;

class Counter {
    private:
        int count; // ������ֵ
    public:
        Counter() : count(0) {} // ���캯������ʼ��������Ϊ0
        void increment() { count++; } // ���Ӽ���
        void decrement() { if(count > 0) count--; } // ���ټ�����������С��0
        int get_count() const { return count; } // ���ص�ǰ����
};

int main() {
    Counter c;
    c.increment();
    c.increment();
    cout << "Count: " << c.get_count() << endl; // ��� "Count: 2"
    c.decrement();
    cout << "Count: " << c.get_count() << endl; // ��� "Count: 1"
    return 0;
}
