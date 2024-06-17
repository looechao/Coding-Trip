#include <func.h>

int main(int argc, char* argv[])
{
    // ./1_server.c 192.168.68.128 1234
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
    char buf[4096];
    //sleep(5);
    ssize_t sret = recv(netfd, buf, sizeof(buf), 0);
    printf("sret = %ld, buf = %s\n", sret, buf);
    return 0;
}

