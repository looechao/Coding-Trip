#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1;
    string str2("\0");   //str2���ڴ���´�,���ÿ�
    getline(cin,str1);  //��ȡһ���ַ�
    for(int i=0;i<str1.size();i++)
    {
        if(!ispunct(str1.at(i)))
        {
            str2+=str1.at(i);  //���Ǳ����ŵ��ַ������´�
        }
    }
    cout<<str2;
}
