#include<stdio.h>
#include<stdlib.h>
typedef int E;

typedef struct node{
    E data;
    struct node* next;
}Node;

void add_before_head(Node** head, E val){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

Node* rotateRight(Node* head, E k){
    if (!head || k <= 0) return head;
    
    Node* start = head;
    while (k > 0) {
        Node* second_last = head;
        while (second_last->next && second_last->next->next) {
            second_last = second_last->next;
        }
        
        add_before_head(&start, second_last->next->data);
        free(second_last->next); // free the memory of the node that is removed
        second_last->next = NULL;

        head = start;
        k--;
    }
    return start;
}

int main(){
    Node* list = malloc(sizeof(Node));
    Node* start = list;
    list->data = 6;
    list->next = NULL;
    add_before_head(&list,9);
    add_before_head(&list,4);
    add_before_head(&list,5);
    add_before_head(&list,3);
    add_before_head(&list,2);

    Node* rotated = rotateRight(list, 2);

    printf("Before rotation:\n");
    while (list){
        printf("val %d\n", list->data);
        list = list->next;
    }

    printf("After rotation:\n");
    while (rotated){
        printf("val %d \n", rotated->data);
        rotated = rotated->next;
    }

    list = start;
    while (list) {
        Node* next = list->next;
        free(list);
        list = next;
    }
    return 0;
}