#include<stdio.h>


typedef struct node{
    int data;
    struct node* next;
}Node;
//OnePass����
//��ͷ��β����һ�Σ���ǰʹ��Node�������᲻��ʶ


//ͷ�巨����ڵ�
Node* addNode(Node* head, int data){
	//�����ڵ�
    Node* new_node = malloc(sizeof(Node));
    if(!new_node){
        printf("Error:malloc failed in addNode.\n");
        exit(1);
    }
    //��ʼ���ڵ�
    new_node->data = data;
    new_node->next =head;
    head = new_node;
    
    return head;
}

int main(void){
	Node* head = NULL; //������
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);  

    return 0;
}	