#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> num(10,0);
    for(int i=0;i<num.size();i++)
    {
        cin>>num[i];
    }
    // ʹ�õ�����������Ԫ�ص�ֵ�����ԭ��������
    for(auto it = num.begin(); it != num.end(); ++it)
    {
        *it *= 2;
    }
    // ���vector���������
    for(const auto &value : num)
    {
        cout << value << " ";
    }
    return 0;
}
