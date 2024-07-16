#include <iostream>
#include <vector>
#include <functional>
using std::vector;
using std::cout;
using std::endl;
using std::swap;

template<typename T, typename Compare = std::less<T>>

class MyQsort{
public:
    MyQsort(T* arr, size_t size, Compare com = Compare())
    :_vec(arr, arr + size)
    ,_com(com){}

    void quick(int left, int right){
        if(left < right){
            int pivotIndex = partition(left, right);
            quick(left, pivotIndex - 1);
            quick(pivotIndex + 1, right);
        }
    }
    
    void print(){
        for (const auto &ele : _vec){
            cout << ele << " ";
        }
        cout << endl;
    }

private:
    vector<T> _vec;
    Compare _com;

    int partition(int left, int right){
        T pivot = _vec[right];
        int i = left - 1;
        for(int j = left; j < right; ++j){
            if(_com(_vec[j], pivot)){
                ++i;
                swap(_vec[i], _vec[j]);
            }
        }

        swap(_vec[i+1], _vec[right]);
        return i + 1;
    }
};

void test0(){
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    MyQsort<int> sorter(arr, size);
    sorter.quick(0, size - 1);
    sorter.print();
}

int main()
{
    test0();
    return 0;
}

