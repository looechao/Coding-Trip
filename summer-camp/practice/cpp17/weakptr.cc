#include <iostream>
#include <memory>
using std::weak_ptr;
using std::shared_ptr;
using std::cout;
using std::endl;

void test0(){
    weak_ptr<int> wp;
    shared_ptr<int> sp(new int(5));
    weak_ptr<int> wp2(sp);
    wp = sp;
    cout << wp.use_count() << endl;

    //weakptr不能直接访问其指向的资源
    
    //没有管理资源的shared_ptr隐式转换位false
    //管理资源的shared_ptr隐式转换为true
    //weak_ptr无法这样使用
    if(sp){
        cout << "hello" << endl;
    }
}


weak_ptr<int> wp2;


void test1(){
    weak_ptr<int> wp;
    shared_ptr<int> sp(new int(5));
    wp = sp;
    wp2 = sp;
    shared_ptr<int> sp2 = wp.lock();
    if(sp2){
        cout << "upgrade successful!!" << endl;
        cout << *sp2 << endl;
    }else{
        cout << "upgrade failed!" << endl;
    }

    cout << wp.use_count() << endl;
}


int main()
{
    test1();
    bool flag = wp2.expired();
    if(flag){
        cout << "expired " << endl;
    }else{
        cout << "not expired" << endl;
    }
    return 0;
}

