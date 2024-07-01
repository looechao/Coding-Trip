#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void test0(){
    vector<int> nums(10, 0);
    for(int i = 1; i <= 10; i++){
        nums[i-1] = i;
    }
    for(ssize_t idx = 0; idx < nums.size(); ++idx){
        cout << nums[idx] << " ";
    }
    cout << endl;

    auto it = nums.begin();
    
    while(it != nums.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

