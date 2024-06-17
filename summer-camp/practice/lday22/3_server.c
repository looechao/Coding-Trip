#include <func.h>

int main(int argc, char* argv[])
{
    // ./2_azhen.c 192.168.68.128 1234
    ARGS_CHECK(argc, 3);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr; //服务端地址的结构体初始化
    addr.sin_family = AF_INET;
    //向ip结构体中传入ip地址和端口号参数
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    int ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    ERROR_CHECK(ret, -1, "bind");
    listen(sockfd, 10);   //DDOS攻击的点
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr); //该变量必须初始化
    int netfd =  accept(sockfd,(struct sockaddr *)&clientAddr, &clientAddrSize);
    printf("netfd = %d\n", netfd);
    printf("client ip = %s, port = %d\n",
           inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
    //1 fd_set rdset;
    int epfd = epoll_create(1); //epoll_create 取代定义 fd_set这个对象
    //2 设置监听 取代fd_set
    //如果使用epoll_ctl 可以在循环外面使用
    struct epoll_event event;
    event.data.fd = STDIN_FILENO;
    event.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event); //fd_set
    //每次用完event之后都要重新赋值
    event.data.fd = netfd;
    event.events = EPOLLIN; //读事件
    epoll_ctl(epfd, EPOLL_CTL_ADD, netfd, &event);
    char buf[4096];

    while(1){
        //FD_ZERO(&rdset);
        //FD_SET(STDIN_FILENO, &rdset);
        //FD_SET(netfd, &rdset);
        //select(netfd+1, &rdset, NULL, NULL, NULL);
        // 4 更换成epoll wait
        // 现申请一个数组
        struct epoll_event readySet[2];
        int readyNum = epoll_wait(epfd, readySet, 2, -1); //永久等待使用-1参数
       // if(FD_ISSET(STDIN_FILENO, &rdset)){
       //     //memset(buf, 0, sizeof(buf));
       //     bzero(buf, sizeof(buf));
       //     ssize_t sret = read(STDIN_FILENO, buf, sizeof(buf));
       //     //send(sockfd, buf, strlen(buf), 0);
       //     send(netfd, buf, sret, 0);
       // }
       // if(FD_ISSET(netfd, &rdset)){
       //     bzero(buf, sizeof(buf));
       //     ssize_t sret = recv(netfd, buf, sizeof(buf), 0);
       //     printf("buf = %s\n", buf);
       // }
       
       //从就绪事件集合中进行操作 
        for(int i = 0; i < readyNum; ++i){
            if(readySet[i].data.fd == STDIN_FILENO){
                //memset(buf, 0, sizeof(buf));
                bzero(buf, sizeof(buf));
                ssize_t sret = read(STDIN_FILENO, buf, sizeof(buf));
                //send(sockfd, buf, strlen(buf), 0);
                if(sret == 0){
                    send(netfd, "nishigehaoren", 13, 0);
                    goto end;
                }
                send(netfd, buf, sret, 0);
            }
            else if(readySet[i].data.fd == netfd){
                bzero(buf, sizeof(buf));
                ssize_t sret = recv(netfd, buf, sizeof(buf), 0);
                if(sret == 0){
                    printf("hehe\n");
                    goto end;
                }
                printf("buf = %s\n", buf);
            }
        }
    }
end:   
    close(netfd);
    return 0;
}

