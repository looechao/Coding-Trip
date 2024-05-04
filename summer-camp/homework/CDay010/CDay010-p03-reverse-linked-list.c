#include<stdio.h>
#include<stdlib.h>
typedef int E;

typedef struct node_s{
    E data;
    struct node_s* next;
} Node;

void add_before_head(Node** list, E val){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *list;
    *list = new_node;
}

Node* reverseList(Node* list){
    Node* new_list = NULL;
    while(list){
        add_before_head(&new_list,list->data);
        list = list->next;
    }
    return new_list;
}

void display_list(Node* list){
    while(list){
        printf("%d->", list->data);
        list = list->next;
    }
    printf("NULL");
}

int main(){
    Node* list = NULL;
    for(int i=10; i>=1; i--){
        add_before_head(&list,i);
    }
    printf("反转前的链表是：\n");
    display_list(list);
    printf("\n反转后的链表是：\n");
    Node* relist = reverseList(list);
    display_list(relist);
}