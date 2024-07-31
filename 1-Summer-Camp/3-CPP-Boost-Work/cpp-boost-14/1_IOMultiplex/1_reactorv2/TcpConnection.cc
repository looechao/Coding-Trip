#include "TcpConnection.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ostringstream;

TcpConnection::TcpConnection(int fd)
: _sockIO(fd)
, _sock(fd)
, _localAddr(getLocalAddr())
, _peerAddr(getPeerAddr())
{

}

TcpConnection::~TcpConnection()
{

}

void TcpConnection::send(const string &msg)
{
    _sockIO.writen(msg.c_str(), msg.size());
}

string TcpConnection::receive()
{
    char buff[65535] = {0};
    _sockIO.readLine(buff, sizeof(buff));

    return string(buff);
}

//查看连接是否断开
bool TcpConnection::isClosed() const
{
    char buf[10] = {0};
    int ret = ::recv(_sock.fd(), buf, sizeof(buf), MSG_PEEK);

    return (0 == ret);
}

string TcpConnection::toString()
{
    ostringstream oss;
    oss << _localAddr.ip() << ":"
        << _localAddr.port() << "---->"
        << _peerAddr.ip() << ":"
        << _peerAddr.port();

    return oss.str();
}

//获取本端的网络地址信息
InetAddress TcpConnection::getLocalAddr()
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr );
    //获取本端地址的函数getsockname
    int ret = getsockname(_sock.fd(), (struct sockaddr *)&addr, &len);
    if(-1 == ret)
    {
        perror("getsockname");
    }

    return InetAddress(addr);
}

//获取对端的网络地址信息
InetAddress TcpConnection::getPeerAddr()
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr );
    //获取对端地址的函数getpeername
    int ret = getpeername(_sock.fd(), (struct sockaddr *)&addr, &len);
    if(-1 == ret)
    {
        perror("getpeername");
    }

    return InetAddress(addr);
}
//添加三个回调的注册
void TcpConnection::setNewConnectionCallback(const TcpConnectionCallback &cb)
{
    _onNewConnection = cb;
}

void TcpConnection::setMessageCallback(const TcpConnectionCallback &cb)
{
    _onMessage = cb;
}

void TcpConnection::setCloseCallback(const TcpConnectionCallback &cb)
{
    _onClose = cb;
}

//添加三个回调的执行
void TcpConnection::handleNewConnectionCallback()
{
    if(_onNewConnection)
    {
        /* shared_ptr<TcpConnection>; */
        /* shared_ptr<TcpConnection> ccc(new TcpConnection()); */
        /* shared_ptr<TcpConnection> ccc(this); */
        /* _onNewConnection(shared_ptr<TcpConnection>(this)); */
        _onNewConnection(shared_from_this());
    }
    else
    {
        cout << "nullptr == _onNewConnection" << endl;
    }
}
void TcpConnection::handleMessageCallback()
{
    if(_onMessage)
    {
        _onMessage(shared_from_this());
    }
    else
    {
        cout << "nullptr == _onMessage" << endl;
    }
}

void TcpConnection::handleCloseCallback()
{
    if(_onClose)
    {
        _onClose(shared_from_this());
    }
    else
    {
        cout << "nullptr == _onClose" << endl;
    }
}

