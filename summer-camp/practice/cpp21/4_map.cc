#include <iostream>
#include <map>
#include <string>

using std::multimap;
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
    multimap<int, string, std::less<int>> num = {
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
    cout << endl << "multimap的insert操作" << endl;
    num.insert({8, "test"});
    display(num);

    /* cout << "map的下标操作" << endl; */
    /* cout << "num[2] = " << num[2] << endl; //查找 */
    /* cout << "num[6] = " << num[6] << endl; //插入 */
    /* display(num); */
    /* cout << endl; */
    /* num[6] = "test2"; //修改 */
    /* display(num); */

    /* const map<int, string> tmp = {{1, "wuhan"}}; */
}


int main()
{
    test0();
    return 0;
}

