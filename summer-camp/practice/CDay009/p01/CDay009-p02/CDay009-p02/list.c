#include<stdio.h>
#include<stdlib.h>
#include"list.h"


void add_before_head(Node** plist, E val) {
	//1.�����½ڵ�
	Node* new_node = malloc(sizeof(Node));
	if (!new_node) {
		printf("Error: malloc failed in add_before_head");
		exit(1);
	}
	//2.��ʼ���ڵ�
	new_node->data = val;
	new_node->next = *plist;
	//plist = &new_node;
	*plist = new_node;
}

void display_list(Node* list) {
	while (list!=NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
}

Node* search_list(Node* list, int val) {
	//������
	if (!list) {
		return NULL;
	}
	//���� f��i��;val==a[i] ;
	while (list != NULL) {
		if (list->data == val) {
			return list;
		}
		list = list->next;
	}
	return NULL;
}

//�ͷŽڵ�
void free_list(Node* list) {
	//�ж��Ƿ�Ϊ��
	if(!list){
		return;
	}
	while(list){
		Node* new_node = list->next;
		free(list);
		list = new_node;
	}
}