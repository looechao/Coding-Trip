#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


void test0(){
    vector<int> vec;
    cout << "size:" << vec.size() << " capacity:" << vec.capacity() << endl;
    cout << "vec.push_back(1)" << endl; 
    vec.push_back(1);
    cout << "size:" << vec.size() << " capacity:" << vec.capacity() << endl;

    
    cout << "vec.push_back(2)" << endl; 
    vec.push_back(2);
    cout << "size:" << vec.size() << " capacity:" << vec.capacity() << endl;


    cout << "vec.push_back(3)" << endl; 
    vec.push_back(3);
    cout << "size:" << vec.size() << " capacity:" << vec.capacity() << endl;
    
    cout << "vec.pop_back()" << endl; 
    vec.pop_back();
    cout << "size:" << vec.size() << " capacity:" << vec.capacity() << endl;
    

    cout << "vec.clear()" << endl; 
    vec.clear();
    cout << "size:" << vec.size() << " capacity:" << vec.capacity() << endl;
}

int main()
{
    test0();
    return 0;
}

