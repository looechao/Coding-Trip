#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

int main()
{
    list<const char*> clist{"string1","string2"};
    vector<string> stringvec(clist.cbegin(),clist.cend());
    for(auto i=stringvec.begin();i<=stringvec.end();i++)    //ʹ�õ���������Ԫ��
        cout<<*i<<" ";
    cout<<endl;
    return 0;
}
