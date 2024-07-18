#include <iostream>
#include <unordered_map>
#include <string>

using std::pair;
using std::string;
using std::make_pair;
using std::unordered_map;
using std::cout;
using std::endl;

template <typename Container>
void display(const Container &con)
{
    for(auto &ele : con)
    {
        cout << ele.first << " " << ele.second << endl;
    }
    cout << endl;
}

void test0(){
    // 1 存放的是key-value类型，key值是唯一的，布恩那个重复
    //  value 值即可以重复，也可以不重复
    // 2 key值是没有顺序的
    // 3 底层使用的是hash
    unordered_map<int, string> num = {
        {1, "wuhan"},
        {5, "beijing"},
        pair<int, string>(6, "shanghai"),
        pair<int, string>(6, "beijing"),
        make_pair(9, "hubei"),
        make_pair(4, "hubei"),
    };
    display(num);

    cout << "map的下标操作" << endl;
    cout << "num[4] = " << num[4] << endl; //查找
    cout << "num[10] = " << num[10] << endl; //插入
    display(num);
    cout << endl;
    num[10] = "test2"; //修改
    display(num);

}


int main()
{
    test0();
    return 0;
}

