#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void test0(){
    vector<int> nums;
    cout << "nums's size" << nums.size() << endl;
    cout << "nums's capacity" << nums.capacity() << endl; 
    nums.push_back(1);
    cout << "nums's size" << nums.size() << endl;
    cout << "nums's capacity" << nums.capacity() << endl; 
    nums.push_back(1);
    cout << "nums's size" << nums.size() << endl;
    cout << "nums's capacity" << nums.capacity() << endl; 
    nums.push_back(1);
    cout << "nums's size" << nums.size() << endl;
    cout << "nums's capacity" << nums.capacity() << endl; 
    nums.push_back(1);
    cout << "nums's size" << nums.size() << endl;
    cout << "nums's capacity" << nums.capacity() << endl; 
    nums.push_back(1);
    cout << "nums's size" << nums.size() << endl;
    cout << "nums's capacity" << nums.capacity() << endl; 
    nums.push_back(1);
    cout << "nums's size" << nums.size() << endl;
    cout << "nums's capacity" << nums.capacity() << endl; 
    nums.push_back(1);
    cout << endl;
    cout << &nums[0]<<endl;
    cout << &nums[1]<<endl;
    cout << &nums <<endl;
    vector<int>::iterator it = nums.begin();
    cout << &*nums.begin() << endl;

    // vector的元素一定在堆上
    // vector对象可以创建在栈上，也可以创建在堆上
    vector<int>* p = new vector<int>();
    p->push_back(10);
    delete p;
}

void test3(){
    // 如果一个vector要存放很多个元素
    // 这种有参构造不仅开辟了存放元素的空间
    // 而且对所有元素进行了初始化
    vector<int> nums(10);
    
    vector<int> nums2;

    nums2.reserve(10); //开辟空间，但是不存放元素
    cout << "nums2's size" << nums2.size() << endl;
    cout << "nums2's capacity" << nums2.capacity() << endl; 
}

int main()
{
    test3();
    return 0;
}

