#include<stdio.h>


typedef struct node{
    int data;
    struct node* next;
}Node;
//OnePass过程
//从头到尾遍历一次，提前使用Node编译器会不认识


//头插法插入节点
Node* addNode(Node* head, int data){
	//创建节点
    Node* new_node = malloc(sizeof(Node));
    if(!new_node){
        printf("Error:malloc failed in addNode.\n");
        exit(1);
    }
    //初始化节点
    new_node->data = data;
    new_node->next =head;
    head = new_node;
    
    return head;
}

int main(void){
	Node* head = NULL; //空链表
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);  

    return 0;
}	