#include<iostream>

using namespace std;

// ����֮�͵ĺ���
int sum(int a, int b){
    return a+b;
}

// ������֮�͵ĺ���
float sum(float a, float b){
    return a+b;
}

int main(){
    int x = 1, y = 2;
    float m = 1.5, n = 2.5;

    cout << "Integer sum: " << sum(x, y) << endl;  // ��� "Integer sum: 3"
    cout << "Float sum: " << sum(m, n) << endl;    // ��� "Float sum: 4"

    return 0;
}
