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
    fd_set rdset;
    char buf[4096];
    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO, &rdset);
        FD_SET(netfd, &rdset);
        select(netfd+1, &rdset, NULL, NULL, NULL);
        if(FD_ISSET(STDIN_FILENO, &rdset)){
            //memset(buf, 0, sizeof(buf));
            bzero(buf, sizeof(buf));
            ssize_t sret = read(STDIN_FILENO, buf, sizeof(buf));
            //send(sockfd, buf, strlen(buf), 0);
            send(netfd, buf, sret, 0);
        }
        if(FD_ISSET(netfd, &rdset)){
            bzero(buf, sizeof(buf));
            ssize_t sret = recv(netfd, buf, sizeof(buf), 0);
            printf("buf = %s\n", buf);
        }
    }
    return 0;
}

