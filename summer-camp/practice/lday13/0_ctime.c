#include <func.h>

void *threadFunc(void *arg){
    time_t now = time(NULL);
    //char *p = ctime(&now);
    char buf[1024] = {0};
    char *p = ctime_r(&now, buf);
    printf("Before child thread, time = %s\n", p);
    sleep(5);
    printf("After child thread, time = %s\n", p);
    pthread_exit(NULL);
}


int main(int argc, char* argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, NULL);
    sleep(1);
    time_t now = time(NULL);
    //char *p = ctime(&now);
    char buf[1024] = {0};
    char *p = ctime_r(&now, buf);
    printf("Before child thread, time = %s\n", p);
    pthread_join(tid, NULL);
    return 0;
}

