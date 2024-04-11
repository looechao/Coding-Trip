#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> num(10,0);
    for(int i=0;i<num.size();i++)
    {
        cin>>num[i];
    }
    // 使用迭代器将所有元素的值都变成原来的两倍
    for(auto it = num.begin(); it != num.end(); ++it)
    {
        *it *= 2;
    }
    // 输出vector对象的内容
    for(const auto &value : num)
    {
        cout << value << " ";
    }
    return 0;
}
