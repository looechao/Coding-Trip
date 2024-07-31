#include "EventLoop.h"
#include "Acceptor.h"
#include "TcpConnection.h"
#include <unistd.h>

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

EventLoop::EventLoop(Acceptor &accptor)
: _epfd(createEpollFd())
, _evtList(1024)
, _isLooping(false)
, _acceptor(accptor)
{
    //需要将listenfd放在红黑树上进行监听
    int listenfd = _acceptor.fd();
    addEpollReadFd(listenfd);
}

EventLoop::~EventLoop()
{
    close(_epfd);
}

//是否在循环
void EventLoop::loop()
{
    _isLooping = true;
    while(_isLooping)
    {
        waitEpollFd();
    }
}

void EventLoop::unloop()
{
    _isLooping = false;
}

//封装epoll_wait
void EventLoop::waitEpollFd()
{
    //获取vector的第一个元素的首地址
    int nready = 0;
    do
    {
        nready = ::epoll_wait(_epfd, &*_evtList.begin(), _evtList.size(), 3000);
    }while(-1 == nready && errno == EINTR);

    if(-1 == nready)
    {
        cerr << "-1 == nready " << endl;
        return;
    }
    else if(0 == nready)
    {
        cout << ">>epoll_wait timeout!!!" << endl;
    }
    else
    {
        //为了防止文件描述符的数目超过1024，我们可以手动扩容
        if(nready == (int)_evtList.size())
        {
            _evtList.resize(2 * nready);
        }

        for(int idx = 0; idx < nready; ++idx)
        {
            int fd = _evtList[idx].data.fd;
            int listenfd = _acceptor.fd();

            if(fd == listenfd)
            {
                handleNewConnection();//处理新的连接请求
            }
            else
            {
                handleMessage(fd);//处理老的连接
            }
        }
    }
}

//处理新的连接
void EventLoop::handleNewConnection()
{
    //如果connfd是正常的，就表明三次握手完全成功
    int connfd = _acceptor.accept();
    if(connfd < 0)
    {
        perror("handleNewConnection");
        return;
    }

    //将文件描述符connfd放在红黑树上进行监听
    addEpollReadFd(connfd);

    //三次握手建立成功，就可以创建出TcpConnection连接
    TcpConnectionPtr con(new TcpConnection(connfd));

    //就可以在此处将EventLoop中的三个数据成员传递给
    //TcpConnection的对象
    con->setNewConnectionCallback(std::move(_onNewConnection));//连接建立
    con->setMessageCallback(std::move(_onMessage));//消息到达
    con->setCloseCallback(std::move(_onClose));//连接断开

    //存储文件描述符connfd与连接TcpConnection的键值对
    /* _conns.insert({connfd, con}); */
    _conns[connfd] = con;

    //连接已经建立了，就可以执行连接建立的事件
    con->handleNewConnectionCallback();
}

//处理老的连接上的数据
void EventLoop::handleMessage(int fd)
{
    auto it = _conns.find(fd);
    if(it != _conns.end())
    {
        //回调onMessage就可以了
        bool flag = it->second->isClosed();
        if(flag)//已经断开
        {
            //处理连接断开的事件
            it->second->handleCloseCallback();//连接断开的事件
            //连接断开需要将文件描述符从红黑树上摘除掉
            delEpollReadFd(fd);
            //还需要将文件描述符与连接的键值对从map中删除掉
            _conns.erase(it);
        }
        else
        {
            //处理消息（文件描述符可读）
            it->second->handleMessageCallback();//消息到达
        }
    }
    else
    {
        cout << "连接是不存在的" << endl;
        return;
    }
}

//封装epoll_create函数
int EventLoop::createEpollFd()
{
    int fd = ::epoll_create(1);
    if(fd < 0)
    {
        perror("createEpollFd");
        return -1;
    }
    return fd;
}

//将文件描述符放在红黑树上进行监听
void EventLoop::addEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.events = EPOLLIN;
    evt.data.fd = fd;

    int ret = ::epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &evt);
    if(ret < 0)
    {
        perror("addEpollReadFd");
        return;
    }
}

//将文件描述符从红黑树上取消监听
void EventLoop::delEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.events = EPOLLIN;
    evt.data.fd = fd;

    int ret = ::epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, &evt);
    if(ret < 0)
    {
        perror("delEpollReadFd");
        return;
    }
}

void EventLoop::setNewConnectionCallback(TcpConnectionCallback &&cb)
{
    _onNewConnection = std::move(cb);
}

void EventLoop::setMessageCallback(TcpConnectionCallback &&cb)
{
    _onMessage = std::move(cb);
}

void EventLoop::setCloseCallback(TcpConnectionCallback &&cb)
{
    _onClose = std::move(cb);
}

