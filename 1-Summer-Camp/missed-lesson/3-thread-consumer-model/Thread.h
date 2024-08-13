#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

class Thread{
public:
    Thread();
    virtual ~Thread();
    // 线程运行与停止的函数
    void start();
    void join();

    //线程入口函数
    void* threadFunc(void *arg);

    //线程执行任务的函数
    virtual void run() = 0;

private:
    pthread_t thid; //线程id
    bool _isRunning; //标识线程是否在运行
};
#endif
