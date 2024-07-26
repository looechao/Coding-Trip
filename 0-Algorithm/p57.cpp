#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    //����һ��map
    string fname = "", name = "";
    vector<string> vec={"Tom","Jerry","Lucy"};
    map<string,vector<string>> family = {{"Green",vec},{"White",vec}};

    //����Ӣ������ϰ�ߴ�ӡ���֣���Tom.Green
    for(auto &member : family)
    {
        cout << "Member is:" << " " << endl;
        for(auto it = member.second.begin(); it != member.second.end();++it)
            cout << *it << "." << member.first << endl;
            cout << endl;
    }

    //������family name,Ȼ���Լ�name
    while (cin >> fname >> name)
          family[fname].push_back(name);

    //�ٴ����
    for(auto &member : family)
    {
        cout << "Member is:" << " " << endl;
        for(auto it = member.second.begin(); it != member.second.end();++it)
            cout << *it << "." << member.first << endl;
        cout << endl;
    }
    return 0;
}
