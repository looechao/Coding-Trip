#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::priority_queue;
using std::cout;
using std::endl;

void test0(){
    // 优先级队列的底层使用的式堆排序，默认是大根堆
    // 步骤：当有新元素插入的时候，会将堆顶与新插入的元素进行比较
    // 如果堆顶比新插入的元素药效，也就是满足std::less, 那么就会
    // 进行置换，将新的元素作为新的堆顶
    // 如果堆顶比新插入的元素要大，也就是不满足std::less, 就不会进行置换
    // 上一次的堆顶依旧是堆顶
    vector<int> vec = {1, 3, 7, 9, 5, 3};
    priority_queue<int> pque;
    
    for(size_t idx = 0; idx != vec.size(); ++idx){
        pque.push(vec[idx]);
        cout << "优先级最高的元素是" << pque.top() << endl;
    }
    while(!pque.empty()){
        cout << pque.top() << " ";
        pque.pop();
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

