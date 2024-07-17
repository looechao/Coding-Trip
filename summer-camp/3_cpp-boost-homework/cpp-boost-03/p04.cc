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
