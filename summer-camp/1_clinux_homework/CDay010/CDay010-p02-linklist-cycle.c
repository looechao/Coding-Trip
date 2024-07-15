#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int E;

typedef struct node_s{
    E data;
    struct node_s* next;
}Node;

bool hasCycle(Node* list){
    if(list == NULL || list->next == NULL){
         return false;  // No loop in an empty list or a single node list
    }
    Node* slowPtr = list;
    Node* fastPtr = list;
    while(fastPtr != NULL && fastPtr->next != NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(fastPtr == slowPtr){
            return true;  // Cycle detected
        }
    }
    return false;  // No cycle detected
}

add_before_head(Node** plist, E val){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *plist;
    *plist = new_node;
}

create_cycle_tail_to_head(Node* list){
    Node* start = list;
    while(list->next!=NULL){
        list = list->next;
    }
    list->next = start;
}


create_cycle_tail_to_mid(Node* list){
    Node* start = list->next;
    while(list->next!=NULL){
        list = list->next;
    }
    list->next = start;
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
    for(int i = 5; i >= 1; i--){
        add_before_head(&list,i);
    }
    create_cycle_tail_to_mid(list);
    bool cycle = hasCycle(list);
    if(cycle){
        printf("该链表有环\n");
    }else{
        printf("该链表无环\n");
    }
    return 0;
}