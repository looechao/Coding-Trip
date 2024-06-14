#include <func.h>

int main(int argc, char* argv[])
{
    // ./4_server 192.168.68.128 1234
    ARGS_CHECK(argc, 3);
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //udp SOCK_DGRAM
    //SOCK_DGRAM datagram 数据报 而不是 流
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    int ret = bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    ERROR_CHECK(ret, -1, "bind"); 
    //服务端先recvfrom
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    char buf[4096] = {0};
    recvfrom(sockfd, buf, sizeof(buf), 0,
             (struct sockaddr *)&clientAddr, &clientAddrSize);
    printf("client ip = %s, port = %d\n",
           inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
    printf("buf = %s \n", buf);
    sendto(sockfd, "hello", 5, 0, 
           (struct sockaddr *)&clientAddr, clientAddrSize);
    sendto(sockfd, "world", 5, 0, 
           (struct sockaddr *)&clientAddr, clientAddrSize);
    close(sockfd);
    return 0;
}

