typedef int E;

//节点
typedef struct node_s {
	int data;
	struct node_s* next;
}Node;

//API

//头插法插入元素
void add_before_head(Node** plist, E val);

//打印链表的所有结点的值
void display_list(Node* list);

//查找链表第一个与指定值相等的节点，若没有这样的节点，则返回NULL
Node* search_list(Node* list, E val);

//写一个方法，释放链表中所有的节点
void free_list(Node* list);