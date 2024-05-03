#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

#define DEFAULT_CAPACITY 8
#define PREALLOC_MAX 4096


Vector* vector_create(void) {
    Vector* v = malloc(sizeof(Vector));
    if (!v) {
        printf("Error:malloc failed in vector_create, can't malloc Vector struct");
        exit(1);
    }
    v->elements = malloc(DEFAULT_CAPACITY * sizeof(E));
    if (!v->elements) {
        free(v);
        printf("Error:malloc failed in vector_create, can't malloc elements");
        exit(1);
    }
    v->capacity = DEFAULT_CAPACITY;
    v->size = 0;
    return v;
}
//扩容策略,用户不用知道
void grow_capacity(Vector* v) {
    int new_capacity = v->capacity < PREALLOC_MAX ?
        v->capacity << 1 : v->capacity + PREALLOC_MAX;
    E* temp = realloc(v->elements, new_capacity * sizeof(E));
    if (!temp) {
        printf("Error: malloc failed in grow_capacity");
        exit(1);
    }
    v->elements = temp;
    v->capacity = new_capacity;
}

void push_back(Vector* v, E val) {
    if (v->size == v->capacity) {
        grow_capacity(v);
    }
    v->elements[v->size++] = val;
    return;
}

void push_front(Vector* v, E val) {
    v->size++;
    if (v->size == v->capacity) {
        grow_capacity(v);
    }
    for (int i = v->size; i >= 1; i--) {
        v->elements[i] = v->elements[i - 1];
    }
    v->elements[0] = val;
    return;
}

E pop_back(Vector* v) {
    E tail_value = v->elements[v->size - 1];
    v->size--;
    v->capacity--;
    return tail_value;
}

E pop_front(Vector* v) {
    E head_value = v->elements[0];
    for (int i = 0; i < v->size - 1; i++) {
        v->elements[i] = v->elements[i + 1];
    }
    v->size--;
    return head_value;
}

//
