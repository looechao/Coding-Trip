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
        sde.push_back(str);    //���ַ������
        if(cin.get()=='\n')
        {
            break;
        }
    }
    for(auto i=sde.begin();i<=sde.end();i++)  //ѭ�����Ԫ��
    {
        cout<<*i<<" ";
    }
    return 0;
}
