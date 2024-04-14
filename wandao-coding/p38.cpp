#include<iostream>

using namespace std;

// 整数之和的函数
int sum(int a, int b){
    return a+b;
}

// 浮点数之和的函数
float sum(float a, float b){
    return a+b;
}

int main(){
    int x = 1, y = 2;
    float m = 1.5, n = 2.5;

    cout << "Integer sum: " << sum(x, y) << endl;  // 输出 "Integer sum: 3"
    cout << "Float sum: " << sum(m, n) << endl;    // 输出 "Float sum: 4"

    return 0;
}
