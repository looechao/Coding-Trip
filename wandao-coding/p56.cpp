#include<iostream>
#include<string>
#include<vector>

using namespace std;

string add_pre_suf(string n,string pre,string suf);

int main()
{
    string name;
    cin>>name;
    string a=add_pre_suf(name,"Mr.","III");
    cout<<a;
    return 0;
}

string add_pre_suf(string n,string pre,string suf)
{
    n.insert(n.begin(),pre.begin(),pre.end());
    n.append(suf);
    return n;
}
