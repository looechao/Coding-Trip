#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::function;
using std::bind;
using std::remove_if;
using std::mem_fn;
using std::for_each;
using std::vector;
using std::cout;
using std::endl;

class Number
{
public:
    Number(size_t data = 0)
    :_data(data)
    {}

    void print() const{
        cout << _data << " ";
    }

    bool isEven() const{
        return (0 == _data % 2);
    }

    bool isPrime() const
    {
        if(1 == _data)
        {
            return false;
        }
        for(size_t idx = 2; idx < _data/2; ++idx)
        {
            if(1 == _data)
            {
                return false;
            }

            for(size_t idx = 2; idx <= _data/2; ++idx)
            {
                if(0 == _data % idx)
                {
                    return false;
                }
            }
        }
        return true;
    }
private:
    size_t _data;
};

void test0(){
    vector<Number> vec;
    for(size_t idx = 1; idx != 30; ++idx)
    {
        vec.push_back(Number(idx));
    }

    //使用for_each进行打印
    for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    cout << endl;

    //删除所有的偶数
    vec.erase(remove_if(vec.begin(), vec.end(), 
              mem_fn(&Number::isEven)), vec.end());   
    //使用for_each进行打印
    for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    cout << endl;
    
    //删除所有的质数
    vec.erase(remove_if(vec.begin(), vec.end(), 
              mem_fn(&Number::isPrime)), vec.end());   
    //使用for_each进行打印
    for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    cout << endl;
}


void test1(){
    
    vector<Number> vec;
    Number num;
    for(size_t idx = 1; idx != 30; ++idx)
    {
        vec.push_back(Number(idx));
    }

    //使用for_each进行打印
    //for_each(vec.begin(), vec.end(), bind(&Number::print, num));
    using namespace std::placeholders;
    function<void(Number)> f = bind(&Number::print, _1);
    for_each(vec.begin(), vec.end(), f);
    //for_each(vec.begin(), vec.end(), bind(&Number::print, _1));
    cout << endl;

    //删除所有的偶数
    vec.erase(remove_if(vec.begin(), vec.end(), 
              mem_fn(&Number::isEven)), vec.end());   
    //使用for_each进行打印
    for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    cout << endl;
    
    //删除所有的质数
    vec.erase(remove_if(vec.begin(), vec.end(), 
              mem_fn(&Number::isPrime)), vec.end());   
    //使用for_each进行打印
    for_each(vec.begin(), vec.end(), mem_fn(&Number::print));
    cout << endl;
}

int main()
{
    test1();
    return 0;
}

