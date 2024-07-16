## 2024/7/16

### p01

下面程序有什么错误？
```cpp
list<int> lst; 
list<int>::iterator iter1 = lst.begin(), iter2 = lst.end(); 
while(iter1 < iter2)
{    
     //....
}
```

### p02

创建和初始化vector的方法，每种都给出一个实例，包括deque和list

- 无参对象
- count个对象
- 迭代器范围
- 大括号
- 拷贝构造或者移动构造

```cpp
void test0(){
    //无参构造
    vector<int> vec1;
    display(vec1);
    
    //多个相同的值
    vector<int> vec2(10,3);
    display(vec2);

    //使用迭代器范围
    vector<int> vec3(vec2.begin(), vec2.end());
    display(vec3);

    //使用大括号
    vector<int> vec4{1,2,3,4,5,6};
    display(vec4);

    //使用拷贝构造
    vector<int> vec5(vec4);
    display(vec5);

    //使用移动构造
    vector<int> vec6(std::move(vec5));
    display(vec6);
}
```


### p03

如果c1和c2是两个容器，下面的比较操作有什么限制
if(c1 < c2)

### p04

使用模板实现一个快速排序算法
```cpp
template<typename T,typename Compare=std::less<T>> 
class MyQsort 
{ 
public:     
    MyQsort(T *arr, size_t size, Compare com);     
    void quick(int left, int right, Compare &com);     
    int partition(int left, int right, Compare &com);     
    void print(); 
private:    
    vector<T> _vec; 
};
```
