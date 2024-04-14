#include<iostream>
#include<string>
#include<vector>
#include<deque>

using namespace std;

int main()
{
    deque<string> sde;
    string str;
    while(cin>>str)
    {
        sde.push_back(str);    //将字符串入队
        if(cin.get()=='\n')
        {
            break;
        }
    }
    for(auto i=sde.begin();i<=sde.end();i++)  //循环输出元素
    {
        cout<<*i<<" ";
    }
    return 0;
}
