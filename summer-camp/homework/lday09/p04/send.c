#include <func.h>
#define MAXSIZE 4096

int main(int argc, char* argv[])
{
    //打开文件
    if(argc != 2){
        error(1,0,"usage: ./%s file", argv[0]);
    }
    int file = open("argv[1]", O_RDONLY);
    int fd = open("pipe1", O_RDWR);
    if(fd == -1){
        error(1, errno, "open pipe1");
    }
   
    char buf[MAXSIZE];
    int nbytes;
    while(nbytes = read(file,buf,MAXSIZE)){
        write(fd,buf,nbytes);
    }
    
    close(file);
    close(fd);


    return 0;
}

