#include<iostream>
#include<string>

using namespace std;

string str1,str2;

int main()
{
    cin>>str1>>str2;
    //将stt1和str2连接起来
    string str=str1+str2;
    cout<<str<<endl;
    //用空格分隔两个字符串
    cout<<str1<<" "<<str2;
    return 0;
}
