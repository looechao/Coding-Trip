typedef int E;

//�ڵ�
typedef struct node_s {
	int data;
	struct node_s* next;
}Node;

//API

//ͷ�巨����Ԫ��
void add_before_head(Node** plist, E val);

//��ӡ��������н���ֵ
void display_list(Node* list);

//���������һ����ָ��ֵ��ȵĽڵ㣬��û�������Ľڵ㣬�򷵻�NULL
Node* search_list(Node* list, E val);

//дһ���������ͷ����������еĽڵ�
void free_list(Node* list);