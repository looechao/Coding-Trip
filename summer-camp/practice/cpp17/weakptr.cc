#include <iostream>
#include <memory>
using std::weak_ptr;
using std::shared_ptr;
using std::cout;
using std::endl;

void test0(){
    weak_ptr<int> wp;
    /* shared_ptr<int> sp(new int(5)); */
    shared_ptr<int> sp;
    weak_ptr<int> wp2(sp);
    wp = sp;
    cout << wp.use_count() << endl;

    //weakptr不能直接访问其指向的资源
    
    //没有管理资源的shared_ptr隐式转换位false
    //管理资源的shared_ptr隐式转换为true
    if(sp){
        cout << "hello" << endl;
    }
}

int main()
{
    test0();
    return 0;
}

