#include <func.h>

int main(int argc, char* argv[])
{
    //1. 先pipe
    int pipe1[2];
    if(pipe(pipe1) == -1){
        error(1,errno, "pipe1");
    }

    int pipe2[2];
    if(pipe(pipe2) == -1){
        error(1,errno, "pipe2");
    }

    //2. fork

    char buf[1024];

    switch(fork()){
    case -1:
        error(1,errno,"fork");
    case 0:
        //子进程逻辑
        close(pipe1[1]); //关闭管道1的写端口
        close(pipe2[0]); //关闭管道2的读端口
        read(pipe1[0], buf, 1024);  //将管道1的内容读如到buf中
        printf("from parent: %s\n",buf);
        write(pipe2[1],"Done!\n",6); //向管道2写入内容
        
        exit(0);
    default:
        //父进程逻辑
        close(pipe1[0]); //关闭管道1的读端口
        close(pipe2[1]); //关闭管道2的写端口
        sleep(2);  
        //向管道1写内容
        write(pipe1[1],"homework done?\n",15);
        //读取子进程的内容
        read( pipe2[0], buf,16);
        printf("from child:%s\n", buf);
        
        exit(0);
    }
    
    return 0;
}

