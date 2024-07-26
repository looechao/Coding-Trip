#include <iostream>
#include <memory>
using std::cout;
using std::endl;


template<typename T> 
class Vector 
{ 
public:     
    Vector()
    : _start(nullptr)
    , _finish(nullptr)
    , _end_of_storage(nullptr)
    {}

    ~Vector(){
        //清空元素
        while(_finish != _start){
            --_finish;
            _alloc.destroy(_finish);
        }
        _alloc.deallocate(_start, capacity());
    }

    void push_back(const T & val){
        while(_finish == _end_of_storage){
            reallocate(); //空间不足重新分配内存
            *_finish = val;
            ++_finish;
        }
    }

    void pop_back(){
        if(_finish != _start){
            --_finish; //移动指针
        }
    }   

    int size(){
        return _finish - _start;
    }

    int capacity() const{
        return _end_of_storage - _start;
    }

    void clear(){
        while(_finish != _start){
            --_finish;
            _alloc.destroy(_finish);
        }
    }

private:     
    void reallocate() //重新分配内存,动态扩容要用的 
    {
        int old_capacity = capacity();
        int new_capacity = old_capacity == 0 ? 1 : old_capacity *2; //翻倍扩容
        
        T* new_start = _alloc.allocate(new_capacity);
        T* new_finish = new_start;

        // 将旧数据复制到新内存
        for(T *p = _start; p != _finish; ++p){
            _alloc.construct(new_finish, *p);
            ++new_finish;
        }
        
        while(_finish != _start){
            --_finish;
            _alloc.destroy(_finish);
        }

        _alloc.deallocate(_start, old_capacity);

        _start = new_start;
        _finish = new_finish;
        _end_of_storage = _start + new_capacity;

    }
private:         
    static std::allocator<T> _alloc;          
    T *_start;                 //指向数组中的第一个元素     
    T *_finish;                //指向最后一个实际元素之后的那个元素     
    T *_end_of_storage;        //指向数组本身之后的位置 
};


template<typename T>
std::allocator<T> Vector<T>::_alloc;

void test0(){
    Vector<int> vec;
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

