#include <iostream>
#include <cstring>
using namespace std;

class String {
    char head[100];

public:
    // 构造函数
    String(char *Head) {
        strncpy(head, Head, sizeof(head) - 1);
        head[sizeof(head) - 1] = '\0';  // 确保结束字符存在
    }

    // 翻转字符串
    void reverse() {
        int len = strlen(head);
        for(int i = 0; i < len / 2; ++i) {
            swap(head[i], head[len - 1 - i]);
        }
    }

    // 打印字符串
    void print() {
        cout << head << endl;
    }
};

int main() {
    String s("Hello, world!");
    s.print();
    s.reverse();
    s.print();
    return 0;
}
