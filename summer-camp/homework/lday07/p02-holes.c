#include <func.h>

int main(int argc, char* argv[])
{
    // ./holes src dst
    if(argc != 3){
        error(1, errno, "Usage: ./holes file1 file2");
    }//参数正确
    int srcfd = open(argv[1], O_RDONLY);
    if(srcfd == -1){
        error(1, errno, "open %s failed", argv[1]);
    }
    int dstfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(dstfd == -1){
        error(1, errno, "open %s failed", argv[2]);
    }
    char empty[4096] = {'\0'};
    char buf[4096];

    int n;
    while((n == read(srcfd, buf, 4096)) > 0){
        if(n == 4096 && memcmp(buf, empty, 4096) == 0){
            lseek(dstfd, n, SEEK_CUR);
        }else{
            write(dstfd, buf, n);
        }
    }
    
    close(srcfd);
    close(dstfd);
    return 0;
}

