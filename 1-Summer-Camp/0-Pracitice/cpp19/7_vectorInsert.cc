#include <iostream>
#include <list>
#include <vector>
using std::vector;
using std::list;
using std::cout;
using std::endl;


template <typename Container>

void display(const Container& con){
    cout << "size = " << con.size() << ", capacity = " << con.capacity() << endl; 
    for(auto &ele : con)
    {
        cout << ele << " ";
    }
    cout << endl;
}


void test0(){
    vector<int> number(10, 3);
    display(number);
    
    cout << "在vector任意位置插入" << endl;
    auto it = number.begin();
    cout << "在vector首部插入1个" << endl;
    number.insert(it, 40);
    display(number);
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << * it << endl;
    number.insert(it, 30);
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << * it << endl;
    cout << "在vector it 插入1个" << endl;
    display(number);

    //插入count个元素
    number.insert(it, 3, 20);
    display(number);
    
    vector<int> vec = {11, 33, 66, 44, 22};
    cout << "*it = " << * it << endl;
    number.insert(it, vec.begin(), vec.end());
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << * it << endl;
    cout << "*it = " << * it << endl;
    display(number);
    
    number.clear();
    number.shrink_to_fit();
    display(number);
}


int main()
{
    test0();
    return 0;
}

