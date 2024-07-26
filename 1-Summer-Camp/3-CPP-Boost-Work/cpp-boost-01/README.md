## p03

题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

## p04


题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

这道题很巧妙，从这种数字的占比可以发现，如果数字频次超过数组长度的一半，那么只要让他们保持连续，总会覆盖到最中间的元素

```cpp
int main()
{
    int size;
    cout << "input size:" << endl;
    cin >> size;
    vector<int> num(size, 0);
    cout << "input number:" << endl;
    for(int i =0; i < size; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    
    cout << num[num.size()/2] << endl;

    return 0;
}
```

