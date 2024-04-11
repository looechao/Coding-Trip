#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char head[100];
public:     // 构造函数
    String(const char *Head){
        strncpy(head, Head, 100-1);
        head[99] = '\0';            //确保字符串结尾
    }
    void reverse() {
        int length = strlen(head);
        for(int i = 0; i < length / 2; i++) {   //实现逆序
            char temp = head[i];
            head[i] = head[length - 1 - i];
            head[length - 1 - i] = temp;
        }
    }
    void print() {
        cout << head << endl;
    }
};

int main() {
    String s("Hello World"); // 声明对象并初始化
    s.print(); // 打印初始字符串
    s.reverse(); // 对字符串逆序处理
    s.print(); // 打印逆序后的字符串
    return 0;
}
