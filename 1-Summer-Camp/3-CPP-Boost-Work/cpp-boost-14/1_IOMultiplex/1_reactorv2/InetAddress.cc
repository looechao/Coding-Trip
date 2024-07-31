#include "InetAddress.h"
#include <strings.h>

InetAddress::InetAddress(const string& ip, unsigned short port)
{
    ::bzero(&_addr, sizeof(struct sockaddr_in));
    _addr.sin_family = AF_INET;
    //shift+k
    _addr.sin_port = htons(port);
    _addr.sin_addr.s_addr = inet_addr(ip.c_str()); //host to network
}

//拷贝构造函数
InetAddress::InetAddress(const struct sockaddr_in &addr)
:_addr(addr)
{

}

//析构函数
InetAddress::~InetAddress()
{
}

string InetAddress::ip() const
{
    //返回一个主机字节序
    return string(inet_ntoa(_addr.sin_addr));
}

unsigned short InetAddress::port() const
{
    //返回一个主机字节序的端口
    return ntohs(_addr.sin_port);
}

//返回指针
const struct sockaddr_in *InetAddress::getInetAddrPtr() const
{
    return &_addr;
}
