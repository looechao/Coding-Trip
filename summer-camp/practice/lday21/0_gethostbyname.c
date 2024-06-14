#include <func.h>

int main(int argc, char* argv[])
{
    // ./o_gethostbyname www.baidu.com
    ARGS_CHECK(argc, 2);
    struct hostent * phost = gethostbyname(argv[1]);
    if(phost == NULL){
        herror("gethostbyname");
        return -1;
    }

    printf("official name = %s\n", phost->h_name);
    for(int i = 0; phost->h_aliases[i] != NULL; ++i){
        printf("alias name = %s\n", phost->h_aliases[i]);
    }
    printf("addr type = %d\n", phost->h_addrtype);
    printf("addr length = %d\n", phost->h_length);
    for(int i = 0; phost->h_addr_list[i]!=NULL; ++i){
        char buf[1024] = {0};
        inet_ntop(phost->h_addrtype,phost->h_addr_list[i],buf,1024);
        printf("ip = %s\n",buf);
    }
    return 0;
}

