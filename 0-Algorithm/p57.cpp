#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    //定义一个map
    string fname = "", name = "";
    vector<string> vec={"Tom","Jerry","Lucy"};
    map<string,vector<string>> family = {{"Green",vec},{"White",vec}};

    //按照英文名称习惯打印名字，如Tom.Green
    for(auto &member : family)
    {
        cout << "Member is:" << " " << endl;
        for(auto it = member.second.begin(); it != member.second.end();++it)
            cout << *it << "." << member.first << endl;
            cout << endl;
    }

    //先输入family name,然后自己name
    while (cin >> fname >> name)
          family[fname].push_back(name);

    //再次输出
    for(auto &member : family)
    {
        cout << "Member is:" << " " << endl;
        for(auto it = member.second.begin(); it != member.second.end();++it)
            cout << *it << "." << member.first << endl;
        cout << endl;
    }
    return 0;
}
