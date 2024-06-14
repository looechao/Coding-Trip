#include <func.h>

void func(){
    time_t now = time(NULL);
    char *p = ctime(&now);
    printf("before, time = %s\n", p);
    sleep(5);
    printf("after, time = %s\n", p);
}

void *threadFunc(void *arg){
    func();
}

int main(int argc, char* argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, NULL);
    sleep(2);
    pthread_join(tid, NULL);
    return 0;
}

