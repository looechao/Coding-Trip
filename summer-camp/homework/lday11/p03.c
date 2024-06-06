#include <func.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* start_routine(void* args){
    long long* sum = (long long*)args;
    for(long long i = 1; i <= 10000000; i++){
        pthread_mutex_lock(&mutex);
        (*sum)++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    long long* value = (long long*)calloc(1, sizeof(long long));
    
    pthread_t tid1, tid2;
    int err = pthread_create(&tid1, NULL, start_routine,(void*)value);
    if(err){
        error(1, err, "pthread1_create");
    }
    
    err = pthread_create(&tid2, NULL, start_routine, (void*)value);
    if(err){
        error(1, err, "pthread2_create");
    }
    

    err = pthread_join(tid1, NULL);
    if(err){
        error(1,err,"pthread2_join %lu\n", tid1);
    }
    err = pthread_join(tid2, NULL);
    if(err){
        error(1,err,"pthread2_join %lu\n", tid2);
    }

    printf("main: value  = %lld\n", *value);
    
    free(value);

    return 0;
}

