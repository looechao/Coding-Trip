#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"vector.h"

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
    printf("�����ڵ�Ԫ���ǣ�\n");
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->elements[i]);
    }
    
    printf("\nɾ����β��Ԫ���ǣ�%d\n", pop_back(v));
    printf("ɾ����ͷ��Ԫ���ǣ�%d\n"
           "���������ڵ�Ԫ����:\n",pop_front(v));
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->elements[i]);
    }
    return 0;
}