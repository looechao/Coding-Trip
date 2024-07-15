#include<stdio.h>
#include<stdlib.h>
typedef int E;


typedef struct node_s{
    E data;
    struct node_s* next;
}Node;

void add_before_head(Node** plink, E val){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *plink;
    *plink = new_node;
}

void add_after_head(Node** plink, E val){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    if(*plink == NULL){
        *plink = new_node;
    }else{
        Node* temp = *plink;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

//使用尾插法进行合并
Node* merge_two_sorted_list(Node* list1, Node* list2){
    Node* dummy_node = NULL;
    while(list1&&list2){
        if(list1->data<=list2->data){
            add_after_head(&dummy_node, list1->data);
            list1 = list1->next;
        }else{
            add_after_head(&dummy_node, list2->data);
            list2 = list2->next;
        }
    }
    while(list2){
        add_after_head(&dummy_node, list2->data);
        list2 = list2->next;
    }
    while(list1){
        add_after_head(&dummy_node, list1->data);
        list1 = list1->next;
    }
    return dummy_node;
}


//使用dummy node 算法进行合并
Node* merge_two_sorted_list2(Node* list1, Node* list2){
    Node dummy_node;
    Node* tail = &dummy_node;
    while(list1&&list2){
        if(list1->data<=list2->data){
            tail->next = list1;
            list1 = list1->next;
        }else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if(list1){
        tail->next = list1;
    }
    if(list2){
        tail->next = list2;
    }
    return dummy_node.next;
}

void display_list(Node* list){
    while(list){
        printf("%d ", list->data);
        list = list->next;
    }
}

int main(){
    Node* link1 = NULL;
    for(int i = 5; i>=1; i-=2){
        add_before_head(&link1, i);
    }
    display_list(link1);
    Node* link2 = NULL;
    for(int i = 6; i>=1; i-=2){
        add_before_head(&link2, i);
    }
    printf("\n");
    display_list(link2);
    printf("\n");
    Node* sorted_list = merge_two_sorted_list2(link1, link2);
    display_list(sorted_list);
    return 0;
}