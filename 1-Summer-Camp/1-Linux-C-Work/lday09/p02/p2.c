#include <func.h>
#define MAXLINE 4096


int main(int argc, char* argv[])
{
    int fd1 = open("pipe1", O_RDONLY);
    if(fd1 == -1){
        error(1, errno, "open pipe1");
    }//打开成功
    //写端
    int fd2 = open("pipe2", O_WRONLY);
    if(fd2 == -1){
        error(1, errno, "open pipe2");
    }

    printf("Established\n");

    char recvline[MAXLINE];
    char sendline[MAXLINE];
    
    fd_set mainfds; 
    FD_ZERO(&mainfds);
    int maxfds;
    FD_SET(STDIN_FILENO, &mainfds);
    
    maxfds = STDIN_FILENO;
    FD_SET(fd1, &mainfds);
    if(fd1 > maxfds){
        maxfds = fd1;
    }


    for(;;){
        struct timeval timeout = {5,0};
        fd_set readfds = mainfds;
        int events = select(maxfds + 1, &readfds, NULL, NULL, NULL);
        switch(events){
        case -1:
            error(1,errno,"select");
        case 0:
            printf("TIMEOUT");
            continue;
        default:
            //printf("timeout tv_esv=%ld, tv_usec = %ld\n", timeout.tv_sec, timeout.tv_usec);
            if(FD_ISSET(STDIN_FILENO, &readfds)){
                fgets(sendline, MAXLINE, stdin);
                write(fd2, sendline, strlen(sendline) + 1);
            }
            // pipe2:
            if(FD_ISSET(fd1, &readfds)){
                int nbytes = read(fd1, recvline, MAXLINE);
                if(nbytes == 0){
                    goto end;
                }else if(nbytes == -1){
                    error(1, errno, "read pipe1");
                }
                printf("from p1: %s", recvline);
            }
        }
    }
end:
    close(fd1);
    close(fd2);

    return 0;
}

