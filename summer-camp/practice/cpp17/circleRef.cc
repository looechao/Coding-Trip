#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Child;

class Parent
{
public:
	Parent()
	{ cout << "Parent()" << endl; }
	~Parent()
	{ cout << "~Parent()" << endl; }
	//只需要Child类型的指针，不需要类的完整定义
	shared_ptr<Child> _spChild;
};

class Child
{
public:
	Child()
	{ cout << "child()" << endl; }
	~Child()
	{ cout << "~child()" << endl; }
	shared_ptr<Parent> _spParent;
};

void test0(){
    shared_ptr<Parent> parentPtr(new Parent());
    cout << parentPtr.use_count() << endl;
    shared_ptr<Child> childPtr(new Child());
    cout << childPtr.use_count() << endl;
    parentPtr->_spChild;
}

int main(){
    test0();
    return 0;
}
