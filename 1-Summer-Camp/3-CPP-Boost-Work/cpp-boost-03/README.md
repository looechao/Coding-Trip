
### p03 

使用map重写词频统计作业。（之前使用的vector，可以比较他们的速率）

```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using std::to_string;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::map;


class Dictionary
{
public:
    void read(const string & filename);
    void store(const string & filename);
private:
    map<string, int> _dict;    
};


void Dictionary::read(const string & filename){
    ifstream ifs(filename);
    string word;
    while(ifs >> word){
        auto it = word.begin();
        while(it != word.end()){
            if(!isalpha(*it)){
                it = word.erase(it);
            }else{
                ++it;
            }
        }
        ++_dict[word];
    }
    ifs.close();
}

void Dictionary::store(const string & filename){
    ofstream ofs(filename);
    for(auto &ele : _dict){
        string line = ele.first + " " + to_string(ele.second) + "\n";
        ofs << line;
    }
    ofs.close();
}

void test0(){
    Dictionary* dict = new Dictionary();
    dict->read("thb");
    dict->store("result");
    delete dict;
}

int main()
{
    test0();
    return 0;
}

```

### P04

使用模板实现一个堆排序算法

使用模板的框架如下：
```cpp
template <typename T, typename Compare = std::less<T>> 
class HeapSort 
{ 
public:  
    HeapSort(T *arr, size_t size);  
    void heapAdjust(size_t ,size_t);  
    void sort();
    void print(); ​ 
private:  
    vector<T> _vec;
    Compare _cmp;
};
```
```cpp
#include <iostream>
#include <vector>
#include <functional>

using std::cout;
using std::endl;

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
    HeapSort(T *arr, size_t size)
    {
        _vec.assign(arr, arr + size);
    }

    void heapAdjust(size_t i, size_t size)
    {
        size_t largest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left < size && _cmp(_vec[largest], _vec[left]))
            largest = left;

        if (right < size && _cmp(_vec[largest], _vec[right]))
            largest = right;

        if (largest != i)
        {
            std::swap(_vec[i], _vec[largest]);
            heapAdjust(largest, size);
        }
    }

    void sort()
    {
        size_t size = _vec.size();
        for (size_t i = size / 2 - 1; i != static_cast<size_t>(-1); --i)
            heapAdjust(i, size);

        for (size_t i = size - 1; i > 0; --i)
        {
            std::swap(_vec[0], _vec[i]);
            heapAdjust(0, i);
        }
    }

    void print()
    {
        for (const auto &elem : _vec)
            cout << elem << " ";
        cout << endl;
    }

private:
    std::vector<T> _vec;
    Compare _cmp;
};

void test0()
{
    std::vector<int> vec = {4, 10, 3, 5, 1};
    HeapSort<int> hs(vec.data(), vec.size());
    hs.sort();
    hs.print();
}

int main()
{
    test0();
    return 0;
}

```

