#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include <sys/epoll.h>
#include <vector>
#include <map>
#include <memory>
#include <functional>

using std::vector;
using std::map;
using std::shared_ptr;
using std::function;

class Acceptor;//前向声明
class TcpConnection;

using TcpConnectionPtr = shared_ptr<TcpConnection>;
using TcpConnectionCallback = function<void(const TcpConnectionPtr &)>;

class EventLoop
{
public:
    EventLoop(Acceptor &accptor);
    ~EventLoop();

    //是否在循环
    void loop();
    void unloop();

    //封装epoll_wait
    void waitEpollFd();

    //处理新的连接
    void handleNewConnection();

    //处理老的连接上的数据
    void handleMessage(int fd);

    //封装epoll_create函数
    int createEpollFd();

    //将文件描述符放在红黑树上进行监听
    void addEpollReadFd(int fd);

    //将文件描述符从红黑树上取消监听
    void delEpollReadFd(int fd);

public:
    //三个回调的注册
    void setNewConnectionCallback(TcpConnectionCallback &&cb);
    void setMessageCallback(TcpConnectionCallback &&cb);
    void setCloseCallback(TcpConnectionCallback &&cb);

private:
    int _epfd;//由epoll_create创建的文件描述符
    vector<struct epoll_event> _evtList;//交给epoll_wait的第二个参数，存放就绪的文件描述符
    bool _isLooping;//标识循环是否在运行
    Acceptor &_acceptor;//获取Acceptor类型的引用，目的就是为了调用其中的accept函数
    map<int, TcpConnectionPtr> _conns;//存放文件描述符与TcpConnection键值对

    TcpConnectionCallback _onNewConnection;//连接建立
    TcpConnectionCallback _onMessage;//消息到达（文件描述符可读）
    TcpConnectionCallback _onClose;//连接断开

};

#endif

