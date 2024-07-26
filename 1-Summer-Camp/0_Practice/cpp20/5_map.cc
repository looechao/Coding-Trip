#include <iostream>
#include <map>
#include <string>
using std::pair;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::make_pair;

template <typename Container>
void display(const Container &con)
{
    for(auto &ele: con)
    {
        cout << ele.first << " " << ele.second << endl;
    }
}

void test0(){
    map<int, string, std::greater<int>> num = {
        pair<int, string>(3, "wangdao"),
        pair<int, string>(5, "wangdao"),
        make_pair(2, "wuhan"),
        make_pair(1, "beijing"),
        {7, "nanjing"},
        {7, "test"},
    };
    display(num);

    cout << "MAP的查找" << endl;
    size_t cnt = num.count(5);
    cout << "cnt = " << cnt <<endl;
    
    auto it = num.find(5);
    if(it != num.end()){
        cout << "该元素是存在的" << endl << it->first << " " << it->second << endl;
    }else{
        cout << "该元素不存在" << endl;
    }
    cout << endl << "map的insert操作" << endl;
    pair<map<int,string>::iterator, bool> ret = num.insert({8, "test"});
    if(ret.second)
    {
        cout << "insert successful " << ret.first->first
            << " " << ret.first->second << endl;
    }else{
        cout << "insert failed, it is already exist" << endl;
    }
    display(num);
}

int main()
{
    test0();
    return 0;
}

