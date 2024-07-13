#include <iostream>
#include <set>
#include <utility>
#include <string>
#include <map>
using namespace std;

void test0(){
    // 这个map中的元素类型是int和string结合而成的pair
    map<int, string> nums;
    map<int, string> nums2{
        {1, "beijing"},
        {2, "shanghai"},
        {3, "wuhan"},
        pair<int, string>(5,"hangzhou"),
        pair<int, string>(3, "dalina"),
        make_pair(1, "guangzhou"),
        make_pair(9, "深圳"),
        make_pair(6, "wuhan")
    };
    
    for(auto &ele : nums2){
        cout << ele.first << " " << ele.second << endl;
    }

    cout << "迭代器遍历:" << endl;
    map<int, string>::iterator it = nums2.begin();
    for(; it != nums2.end(); ++it){
        cout << (*it).first << " " << it->second << endl;
    }
}


int main()
{
    test0();
    return 0;
}

