#include<stdio.h>
#include<stdbool.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
#define MAX_CAPACITY 8
#define DEFAULT_CAPACITY 4

typedef int E;

typedef struct{
    E* elements;
    int front;
    int rear;
    int size;
    int capacity;
}Queue;

//API

//初始化队列
Queue* queue_create(){
    Queue* new_que = malloc(sizeof(Queue));
    if(!new_que){
        printf("Error! Failed to malloc for new_que\n");
        exit(1);
    }
    new_que->size = 0;
    new_que->front = 0;
    new_que->rear = 0;
    new_que->capacity = DEFAULT_CAPACITY;
    new_que->elements = malloc(new_que->capacity*sizeof(E));
    return new_que;
}

bool queue_empty(Queue* q){
    return q->size == 0;
}

bool queue_full(Queue* q){
    return q->size >= q->capacity;
}

//扩大空间，用户不需要知道
void grow_capacity(Queue* q){
    if(q->capacity*2>MAX_CAPACITY){
        printf("Error! Queue is up to MAX_CAPACITY!\n");
        exit(1);
    }
    E* new_elements = malloc(q->capacity*2*sizeof(E));
    int start = 0;
    while(q->front != q->rear){
        new_elements[start] = q->elements[q->front];
        q->front = (q->front+1)%q->capacity;
        start++; 
    }
    q->front = 0;
    new_elements[start] = q->elements[q->rear];
    q->rear = q->size;
    q->capacity *= 2; 
}

void queue_push(Queue* q, E val){
    if(queue_full(q)){
        grow_capacity(q);
        q->elements[q->rear] = val;
        q->size++;
        return;
    }
    if(queue_empty(q)){
        q->elements[q->rear] = val;
        q->size++;
    }else{
        q->rear = (q->rear+1)%q->capacity;
        q->elements[q->rear] = val;
        q->size++;
    }
}
E queue_peek(Queue* q){
    if(queue_empty(q)){
        printf("Error! Empty queue!");
        exit(1);
    }else{
        return q->elements[q->front];
    }
}

E queue_pop(Queue* q){
    int front_val = q->elements[q->front];
    q->front = (q->front+1)%q->capacity;
    q->size--;
    return front_val;
}
//销毁队列
void queue_destroy(Queue* q){
    free(q->elements);
    free(q);
}






// 测试单元
int main(){
    Queue* q = queue_create();
    queue_push(q,1);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, q->elements[q->front],q->elements[q->rear]);
    queue_push(q,2);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, q->elements[q->front],q->elements[q->rear]);
    queue_push(q,3);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_pop(q);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_push(q,4);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_push(q,5);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_push(q,6);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_push(q,7);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_push(q,8);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_push(q,9);
    queue_destroy(q);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    queue_push(q,9);
    printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
    return 0;
}


//   queue_push(q,8);
//     printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);
//     queue_push(q,9);
//     printf("size = %d capacity = %d first element = %d last element = %d \n", q->size, q->capacity, queue_peek(q),q->elements[q->rear]);