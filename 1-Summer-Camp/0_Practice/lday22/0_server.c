#include <func.h>

typedef struct conn_s{
    int netfd;
    int is_alive;
} conn_t;

int main(int argc, char* argv[])
{
    // ./2_server 192.168.68.128 1234
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
    
    conn_t clientArr[10];  //保存所有炼乳客户端的信息
    int curidx = 0; //保存下一个炼乳客户端的下标
    
    char buf[4096];
    fd_set rdset;
    fd_set monitorset;
    FD_ZERO(&monitorset);
    FD_SET(sockfd, &monitorset);
    while(1){
        memcpy(&rdset, &monitorset, sizeof(fd_set));
        select(100, &rdset, NULL, NULL, NULL);
        if(FD_ISSET(sockfd, &rdset)){
            struct sockaddr_in clientAddr;
            socklen_t clientAddrSize = sizeof(clientAddr); //该变量必须初始化
            int netfd =  accept(sockfd,(struct sockaddr *)&clientAddr, &clientAddrSize);
            printf("netfd = %d\n", netfd);
            printf("client ip = %s, port = %d\n",
               inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
            clientArr[curidx].netfd = netfd;
            clientArr[curidx].is_alive = 1; //1 表示存货 0表示已经断开
            FD_SET(netfd, &monitorset);
            ++curidx;
        }
        for(int i = 0; i < curidx; ++i){
            if(clientArr[i].is_alive && FD_ISSET(clientArr[i].netfd, &rdset)){
                //读取该客户端发送的消息并且转发给其它所有的客户端
                bzero(buf, sizeof(buf));
                ssize_t sret = recv(clientArr[i].netfd, buf, sizeof(buf), 0);
                if(sret == 0){
                    clientArr[i].is_alive = 0; //i号客户端已经终止
                    FD_CLR(clientArr[i].netfd, &monitorset);
                    close(clientArr[i].netfd);
                }
                //转发给其他所有的客户端
                for(int j = 0; j < curidx; ++j){
                    if(j == i || clientArr[j].is_alive == 0){
                        continue; //发送的目标是自己或者发送的目标已经关闭，就继续
                    }
                    //相当于做一个广播的操作
                   send(clientArr[j].netfd, buf, strlen(buf), 0);;
                }
            }
        }
    }
    close(sockfd);
    return 0;
}

