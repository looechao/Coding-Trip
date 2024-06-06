#include <func.h>

typedef struct{
    int id;
    int money;
}Account;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  //全局锁，粒度太大

Account acct1 = {1, 100};

int withdraw(Account* acct, int money){
    pthread_mutex_lock(&mutex);
    if(acct->money < money){
        pthread_mutex_unlock(&mutex);
        return 0;
    }
    sleep(1);  //让某种调度出现的概率最大化
    acct->money -= money;
    printf("%lu withdraw money successfully!\n", pthread_self());
    pthread_mutex_unlock(&mutex);
    printf("%lu: withdraw %d\n", pthread_self(), money);
    return money;
}

void* start_routine(void* args){
    withdraw(&acct1, 100);
}

int main(int argc, char* argv[])
{

    pthread_t tid[10];
    int err;
    for(int i = 0; i < 10; i++){
        err = pthread_create(&tid[i], NULL, start_routine, NULL);
        if(err){
            error(1,err,"pthread[%d]", i);
        }
    }
    
    
    for(int i = 0; i < 10; i++){
        pthread_join(tid[i], NULL);
    }

    //打印账号的余额
    printf("balance:%d\n", acct1.money);
    return 0;
}
