#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char head[100];
public:     // ���캯��
    String(const char *Head){
        strncpy(head, Head, 100-1);
        head[99] = '\0';            //ȷ���ַ�����β
    }
    void reverse() {
        int length = strlen(head);
        for(int i = 0; i < length / 2; i++) {   //ʵ������
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
    String s("Hello World"); // �������󲢳�ʼ��
    s.print(); // ��ӡ��ʼ�ַ���
    s.reverse(); // ���ַ���������
    s.print(); // ��ӡ�������ַ���
    return 0;
}
