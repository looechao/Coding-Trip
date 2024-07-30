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
    //需要创建套接字，使用socket函数
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
    {
        perror("socket");
        return -1; //创建失败
    }
    
    //2.主动发起连接请求，使用connect函数，但是需要知道
    //服务器的ip与端口号Port, 使用struct sockadd_in结构体
    struct sockaddr_in seraddr;
    memset(&seraddr, 0, sizeof(seraddr)); //初始化seraddr;
    seraddr.sin_family = AF_INET; //ipv4协议

    //本机字节序host转换成网络字节序inet
    seraddr.sin_port = htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr = inet_addr(argv[1]);
    //连接成功应该会返回一个大于零的值
    int ret = connect(listenfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if(ret < 0) 
    {
        perror("connect\n");
        close(listenfd);
        return -1;
    }

    //3. 如果connect的返回值ok，则表明三次握手建立成功了
    //可以进行数据的收发，read/recv,或者write/send函数
    while(1)
    {
        cout << "客户端想要发送数据给服务器端" << endl;
        string line;
        getline(cin, line);
        int len2 = send(listenfd, line.data(), line.size(), 0);
        if(len2 < 0)
        {
            cout << "客户端发送出错" << endl;
        }
        else if( 0 == len2 )
        {
            cout << " 0 == len2" << endl;
        }

        char buf[128] = {  };
        int len = recv(listenfd, buf, sizeof(buf), 0);
        if(len < 0)
        {
            cout << "客户端接受失败" << endl;
        }
        else if (0 == len){
            cout << "len == 0" << endl;
        }
        else
        {
            cout << "recv msg from server: " << buf << endl;
        }
    }
    close(listenfd);
    return 0;
}

