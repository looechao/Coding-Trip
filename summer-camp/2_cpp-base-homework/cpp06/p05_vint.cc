#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void print(vector<int>& nums){
        
   // // 增强for循环遍历
   // for(auto &ele : nums){
   //     cout << ele << " ";
   // }
   // cout << endl;

    // 迭代器遍历
    auto it = nums.begin();
    while(it != nums.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;

}

void test0(){
    vector<int> arr(10);
    // 下标循环遍历
    for(int idx = 0; idx < arr.size(); ++idx){
        arr[idx] = idx;
    }

    vector<vector<int>> tarray(5);
    tarray.push_back(arr);
    tarray.push_back(arr);
    tarray.push_back(arr);
    tarray.push_back(arr);
    tarray.push_back(arr);
    cout << "2d vector travalsal :" << endl;
    for(auto &ele : tarray){
        print(ele);
    }
}

int main()
{
    test0();
    return 0;
}

