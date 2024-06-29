#include <func.h>
#define MAXLINE 4096

int main(int argc, char* argv[])
{
    for(;;){
        char cmd[MAXLINE];
        printf(">");
        scanf("%s", cmd);
        //创建子进程
        pid_t pid = fork();
        switch(pid){
        case -1:
            error(1,errno,"fork");
        case 0:
            execlp("sh","sh","-c",cmd);
            error(1, errno, "exelcp");
        default:
            int wstatus = waitpid(pid, NULL, 0);
            if(WIFEXITED(wstatus)){
                printf("Child process %d exited with status = %d\n", pid, WEXITSTATUS(wstatus)); 
            }
            if(WIFSIGNALED(wstatus)){
                printf("Child process %d terminated with signal number = %d\n", pid, WTERMSIG(wstatus));
            }
        }
    }
    return 0;
}

