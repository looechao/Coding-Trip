#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include <queue>
#include <mutex>
#include <condition_variable>

using std::queue;
using std::mutex;
using std::unique_lock;
using std::condition_variable;

class TaskQueue
{
public:
    TaskQueue(size_t capa);
    ~TaskQueue();

    //添加任务与获取任务
    void push(const int &value);
    int pop();

    //判空与判满
    bool empty() const;
    bool full() const;

private:
    size_t _capacity;
    queue<int> _que;
    mutex _mutex;
    condition_variable _notEmpty;
    condition_variable _notFull;
};


