#include <func.h>

int main(int argc, char* argv[])
{
    // ./4_client 192.168.68.128 1234
    ARGS_CHECK(argc, 3);
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //udp SOCK_DGRAM
    //SOCK_DGRAM datagram 数据报 而不是 流
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);
    //客户端先sendto
    sendto(sockfd, "zaima?", 5, 0,
           (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    char buf[4096] = {0};
    sleep(5);
    recvfrom(sockfd, buf, sizeof(buf),0,NULL,NULL);
    printf("buf = %s\n", buf);
    close(sockfd);
    return 0;
}

