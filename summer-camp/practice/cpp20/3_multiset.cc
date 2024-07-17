#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <math.h>

using std::cout;
using std::endl;
using std::set;
using std::multiset;
using std::vector;
using std::pair;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test0(){
    //multiset的基本特征
    //1.存放的是key类型，key的值不唯一可以重复
    //2. 默认会按照key值的升序进排列
    //3. 底层实现仍然是红黑树
    multiset<int> num = {1, 3, 4, 3, 5, 9, 8, 5, 7};
    display(num);
}

int main(int argc, char *argv[])
{
    test0();
    return 0;
}


