#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child;

class Parent
{
public:
	Parent()
	{ cout << "Parent()" << endl; }
	~Parent()
	{ cout << "~Parent()" << endl; }
	//只需要Child类型的指针，不需要类的完整定义
	weak_ptr<Child> _wpChild;
};

class Child
{
public:
	Child()
	{ cout << "child()" << endl; }
	~Child()
	{ cout << "~child()" << endl; }
	weak_ptr<Parent> _wpParent;
};

void test0(){
    shared_ptr<Parent> parentPtr(new Parent());
    shared_ptr<Child> childPtr(new Child());
    parentPtr->_wpChild = childPtr;
    childPtr->_wpParent = parentPtr;
}

int main(){
    test0();
    return 0;
}
