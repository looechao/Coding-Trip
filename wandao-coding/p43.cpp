#include<iostream>
#include<string>

using namespace std;

int main()
{
    /*/每次读一行
    string line;
    while(getline(cin,line))
        cout<<line<<endl;
    /*/
    string word;
	//循环读取，每次读一个单词
	cout << "请输入字符串" << endl;
	while (cin>>word)
		cout << word<< endl;
	return 0;
}
