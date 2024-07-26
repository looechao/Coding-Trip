#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;

void test0(){
    vector<int> vec;
    vec.push_back(10);

    bool flag = true;
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << " ";
        if(flag){
            vec.push_back(2); //发生扩容
            flag = false;
            it = vec.begin(); //重置迭代器
        }
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

