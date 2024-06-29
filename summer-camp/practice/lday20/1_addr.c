#include <func.h>

int main(int argc, char* argv[])
{
    // ./1_addr 192.168.118.128 1234
    ARGS_CHECK(argc, 3);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET; //IPV4
    addr.sin_port = htons(atoi(argv[2]));
    // argv[2] char* --> short 再 从小端ｈ 到大端n
    inent_aton();
    return 0;
}

