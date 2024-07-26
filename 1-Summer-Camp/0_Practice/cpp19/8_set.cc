#include <iostream>
#include <set>

using std::set;
using std::cout;
using std::endl;

template <typename Container>
void display(const Container &con)
{
    for(auto &ele: con)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void test0(){
    // set的基本特征
    // 1 存放的是key 类型，key是唯一的，不能重复的
    // count的值表示有还是没有
    set<int> num{1, 3, 4, 3, 5, 9, 8, 5, 7};
    
    size_t cnt = num.count(5);
    display(num);
    cout << cnt << endl;
    auto it = num.find(7);
    if(it != num.end()){
        cout << "查找成功: " << *it << endl;
    }else{
        cout << "查找失败" << endl;
    }
}

int main()
{
    test0();
    return 0;
}

