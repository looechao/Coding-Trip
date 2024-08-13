#include <iostream>
#include <set>
#include <utility>

using namespace std;

void test0(){
    set<int> nums;
    set<int> nums2{1,2,6,8,3,2,1};
    set<int> nums4(nums2.begin(), --nums2.end());

    for(auto & nu: nums4)
    {
        cout << nu << " ";
    }
    cout << endl;
    size_t pos = nums2.count(3);
    cout << pos << endl;

    auto it = nums2.find(2);

    if(it != nums2.end()){
        cout << "该元素存在:" << *it << endl;
    }else{
        cout << "该元素不存在" << endl;
    }

}

void test1(){
    pair<int, string> num = {1, "wangdao"};
    cout << num.first << ":" << num.second << endl;
    
    pair<int, string> num2(2, "hello");
    cout << num2.first << ":" << num2.second << endl;

    string str("world");
    pair<string, double> num3(str, 4.7);
    cout << num3.first << ":" << num3.second << endl;
}

void test2(){
    set<int> nums{1, 4, 8, 7, 2, 1, 3 , 7};

    auto ret = nums.insert(5);
    if(ret.second){
        cout << "插入成功: " << *(ret.first) << endl;
    }else{
        cout << "插入失败: " << *(ret.first) << endl;
    }
    
    set<int> nums2{7, 8, 3, 9, 20, 35};

    nums.insert(nums2.begin(), --nums2.end());

    nums.insert({4, 40, 6});

    for(auto & nu: nums)
    {
        cout << nu << " ";
    }
    cout << endl;

}

//set 遍历

void test3(){
    set<int> nums{1, 2, 3, 4, 5};
    
    /* nums[0] //nums 不支持下标操作 */

    auto it = nums.begin();

    for(; it != nums.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    auto it2 = nums.begin();
    ++it2;
    cout << *it2 << endl;

}

int main()
{
    test2();
    return 0;
}

