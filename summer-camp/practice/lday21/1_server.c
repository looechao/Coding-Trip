#include <func.h>

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc, 3);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;   //填写服务端地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    int ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    ERROR_CHECK(ret, -1, "bind");
    listen(sockfd,10);
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr); //该变量必须初始化
    int netfd = accept(sockfd, (struct sockaddr *)&clientAddr, &clientAddrSize);
    printf("netfd = %d\n", netfd);
    printf("client ip = %s, port = %d\n",
           inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
    char buf[4096] = {0};
    sleep(1);
    ssize_t sret = recv(netfd, buf, sizeof(buf), 0);
    printf("sert = %ld, buf = %s\n", sret, buf);
    return 0;
}

