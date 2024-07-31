#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::cin;

int main(int argc, char** argv)
{   
    if(argc < 2){
        cout << "args error" << endl;
    }
    //需要创建套接字，使用socket函数
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
    {
        perror("socket");
        return -1; //创建失败
    }
    
    //设置端口复用与地址服用
    int opt = 1;
    int retval = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if(retval < 0)
    {
        perror("setsockopt addr");
        close(listenfd);
        return -1;
    }

    int opt2 = 1;
    retval = setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, &opt2, sizeof(opt2));
    if(retval < 0)
    {
        perror("setsockopt port");
        close(listenfd);
        return -1;
    }

    //需要绑定服务器ip与端口号,使用Bind函数
    struct sockaddr_in seraddr;
    memset(&seraddr, 0, sizeof(seraddr)); //初始化seraddr
    seraddr.sin_family = AF_INET;

    //本机字节序转换为网络字节序（包括ip与端口号）
    seraddr.sin_port = htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr = inet_addr(argv[1]);

    int ret = bind(listenfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

    if(ret < 0)
    {
        perror("bind");
        close(listenfd);
        return -1;
    }

    //3. 服务器会处于监听状态，使用listen函数
    ret = listen(listenfd, 128);
    if(ret < 0)
    {
        perror("listen");
        close(listenfd);
        return -1;
    }

    cout << "server is listening..." << endl;
    //服务器会调用accept函数，阻塞等待客户端的连接
    
    int connfd = accept(listenfd, nullptr, nullptr);
    if(connfd < 0)
    {
        perror("accept");
        close(listenfd);
        return -1;
    }

    //5. 连接成功之后，表明三次握手建立陈工
    //就可以进行数据的手法
    while(1)
    {
        char buf[128] = {'\0'};
        int len = recv(connfd, buf, sizeof(buf), 0);
        if(len < 0)
        {
            cout << "服务器接受数据失败" << endl;
        }else if(0 == len)
        {
            cout << "len == 0" << endl;
        }else{
            cout << "recv msg from client: " << buf << endl;
        }
        cout << "服务器想要发送给客户端数据" << endl;
        string line;
        getline(cin, line);
        int len2 = send(connfd, line.data(), line.size(), 0);
        if(len2 < 0){
            cout << "服务器发送出错" << endl;
        }else if(0 == len2){
            cout << "0 == len2" << endl;
        }else{
            cout << "服务器发送成功" << endl;
        }
    }
    close(listenfd);
    close(connfd);
    return 0;
}

