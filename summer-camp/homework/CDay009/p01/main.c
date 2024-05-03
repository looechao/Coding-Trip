#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Vector.h"

int main() {
    Vector* v = vector_create();
    push_front(v, 1);
    push_front(v, 2);
    push_front(v, 3);
    push_front(v, 4);
    push_back(v, 5);
    push_back(v, 6);
    push_back(v, 7);
    push_back(v, 8);
    push_back(v, 9);
    printf("????????\n");
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->elements[i]);
    }
    
    printf("\n?????????%d\n", pop_back(v));
    printf("?????????%d\n"
           "?????????:\n",pop_front(v));
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->elements[i]);
    }
    return 0;
}