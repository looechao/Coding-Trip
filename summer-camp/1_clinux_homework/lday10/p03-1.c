#include <func.h>

void handler(int signo){
    switch(signo){
    case SIGINT:
        printf("caught SIGINT\n");
        break;
    case SIGQUIT :
        printf("caught SIGQUIT\n");
        break;
    case SIGTSTP :
        printf("caught SIGSTOP\n");
        break;
    }
}

int main(int argc, char* argv[])
{

    printf("pid = %d\n", getpid());
    //注册信号处理函数
    
    sighandler_t oldhandler = signal(SIGINT, handler);
   
    if(oldhandler == SIG_ERR){
        error(1, errno, "signal %d", SIGINT);
    }


    oldhandler = signal(SIGQUIT, handler);
    if(oldhandler == SIG_ERR){
        error(1, errno, "signal %d", SIGQUIT);
    }
    
    oldhandler = signal(SIGTSTP, handler);
    if(oldhandler == SIG_ERR){
        error(1, errno, "signal %d", SIGTSTP);
    }



    for(;;){
        sleep(5);
    }
}

