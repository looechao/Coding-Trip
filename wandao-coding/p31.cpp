#include <iostream>
#include <cstring>
using namespace std;

class String {
    char head[100];

public:
    // ���캯��
    String(char *Head) {
        strncpy(head, Head, sizeof(head) - 1);
        head[sizeof(head) - 1] = '\0';  // ȷ�������ַ�����
    }

    // ��ת�ַ���
    void reverse() {
        int len = strlen(head);
        for(int i = 0; i < len / 2; ++i) {
            swap(head[i], head[len - 1 - i]);
        }
    }

    // ��ӡ�ַ���
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
