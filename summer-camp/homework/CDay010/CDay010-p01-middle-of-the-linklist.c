#include<stdio.h>
typedef int E;

typedef struct node_s{
    E data;
    struct node_s* next;
} Node;

int main(){
    Node* list = NULL;
    add_before_head(&list,3);
    add_before_head(&list,2);
    add_before_head(&list,1);

    printf("\n链表的中间元素的值是：%d", middleElenment(list));
}


void add_before_head(Node** list, E val){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *list;
    *list = new_node;
}

int middleElenment(Node* list){
    Node* start = list;
    int length = 0;
    while(list){
        length++;
        list = list->next;
    }
    //找到中间点的位置
    int middle = length/2;
    int count = 0;
    while(count!=middle){
        start = start->next;
        count++;
    }
    return start->data;
}
