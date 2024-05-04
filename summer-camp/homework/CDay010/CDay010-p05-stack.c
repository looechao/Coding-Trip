#include <stdio.h>
#include <stdbool.h>
#include<limits.h>

typedef int E;

typedef struct node {
    E data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;


// API


bool stack_empty(Stack* s){
    return s->size==0;
}


Stack* stack_create(void){
    Stack* new_stack = malloc(sizeof(Stack));
    if(!new_stack){
        printf("Error! Failed to allocate memory for new_stack!\n");
    }
    (*new_stack).top = NULL;
    (*new_stack).size = 0;
}

void stack_destroy(Stack* s){
    while(!stack_empty(s)){
        stack_pop(s);
    }
    free(s);
}

void stack_push(Stack* s, E val){
    Node* new_node = malloc(sizeof(Node));
    if(!new_node){
        printf("Error! Failed to allocate memory for new_node!\n");
    }
    new_node->data = val;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}


E stack_pop(Stack* s){
    if(stack_empty(s)){
        return INT_MIN;
    }
    Node* temp = s->top;
    E val = s->top->data;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return val;
}


E stack_peek(Stack* s){
    if(stack_empty(s)){
        return INT_MIN;
    }
    return s->top->data;
}


//µ¥Ôª²âÊÔ
int main(){
    Stack* s = stack_create();
    printf("size = %d, empty = %d, top =%d  \n", s->size, stack_empty(s), stack_peek(s));
    stack_push(s,10);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_push(s,20);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_push(s,30);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_pop(s);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_pop(s);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_pop(s);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_push(s,1);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_push(s,2);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_push(s,3);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    stack_destroy(s);
    printf("size = %d, empty = %d, top = %d \n", (*s).size, stack_empty(s), stack_peek(s));
    return 0;
}