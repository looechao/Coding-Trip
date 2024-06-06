#include <func.h>
#define MAXSIZE 4096

int main(int argc, char* argv[])
{
    //打开文件
    if(argc != 2){
        error(1,0,"usage: ./%s file", argv[0]);
    }
    int fd = open("pipe1", O_RDWR);
    if(fd == -1){
        error(1, errno, "open pipe1");
    }

    int file = open("argv[1]", O_WRONLY | O_CREAT, 0666);
   
    char buf[MAXSIZE];
    int nbytes;
    while(nbytes = read(fd,buf,MAXSIZE)){
        write(file,buf,nbytes);
    }
    
    close(file);
    close(fd);


    return 0;
}

