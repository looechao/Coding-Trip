#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1;
    string str2("\0");   //str2用于存放新串,故置空
    getline(cin,str1);  //读取一行字符
    for(int i=0;i<str1.size();i++)
    {
        if(!ispunct(str1.at(i)))
        {
            str2+=str1.at(i);  //将非标点符号的字符放入新串
        }
    }
    cout<<str2;
}
