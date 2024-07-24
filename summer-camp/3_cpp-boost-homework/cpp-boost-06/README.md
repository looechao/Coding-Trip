## p01
什么是回调函数，注册回调函数，执行回调函数？(掌握std::bind用法,非常重要)

std::bind的实现原理阅读材料

http://www.cnblogs.com/xusd-null/p/3698969.html
https://www.tuicool.com/articles/iMZ7ba

定义回调函数：回调函数本身是一个普通的函数，可以是普通函数、成员函数或 lambda 表达式。
注册回调函数：将回调函数传递给另一个函数，使其在适当的时候被调用。
执行回调函数：在特定事件发生时，调用已注册的回调函数。
使用 std::bind 注册回调函数
std::bind 是 C++ 标准库中的一个函数，用于将函数和其参数绑定在一起，生成一个新的可调用对象。这在注册回调函数时非常有用，尤其是当回调函数是成员函数时。


## p02
了解std::allocator的用法之后,实现自定义的Vector类

接口形式：

```cpp
template<typename T> 
class Vector 
{ 
public:     
    Vector();     
    ~Vector();          
    void push_back(const T &);      
    void pop_back();         
    int size();     
    int capacity(); 
private:     
    void reallocate();//重新分配内存,动态扩容要用的 
private:         
    static std::allocator<T> _alloc;          
    T *_start;                 //指向数组中的第一个元素     
    T *_finish;                //指向最后一个实际元素之后的那个元素     
    T *_end_of_storage;        //指向数组本身之后的位置 
};

```
vector模型
```bash
 ______________________________
 |_|_|_|_|_|____________________|
 ↑          ↑                    ↑
 _start   _finish            _end_of_storage
```


