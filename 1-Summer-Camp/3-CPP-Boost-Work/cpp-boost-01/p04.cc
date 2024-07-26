#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;


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

