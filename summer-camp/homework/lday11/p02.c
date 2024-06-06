#include <func.h>

typedef struct{
    int left;
    int right;
}Section;

void* start_routine(void* args){
    Section* s = (Section*)args;
    long long sum = 0;
    for(int i = s->left; i <= s->right; i++){
        sum += i;
    }

    return (void*)sum;  //返回指针
}

int main(int argc, char* argv[])
{
    long long n;
    printf("Please input a long long int:");
    scanf("%lld", &n);
    
    Section sec1 = {1, n/2};
    Section sec2 = {n/2+1, n};
    
    pthread_t tid1, tid2;
    int err = pthread_create(&tid1, NULL, start_routine,(void*)&sec1);
    if(err){
        error(1, err, "pthread1_create");
    }
    
    err = pthread_create(&tid2, NULL, start_routine, (void*)&sec2);
    if(err){
        error(1, err, "pthread2_create");
    }
    
    long long result1;
    err = pthread_join(tid1, (void**)&result1);
    if(err){
        error(1,err,"pthread2_join %lu\n", tid1);
    }
    long long result2;
    err = pthread_join(tid2, (void**)&result2);
    if(err){
        error(1,err,"pthread2_join %lu\n", tid2);
    }
    printf("main: sum  = %lld\n", result1+result2);
    return 0;
}

