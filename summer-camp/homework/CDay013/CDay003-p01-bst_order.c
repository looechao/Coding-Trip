#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
#define DEFAULT_CAPACITY 8
#define MAX_PREALLOC 1024
typedef int K;

typedef struct {
    K* elements;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

bool queue_empty(Queue* q) {
	return q->size == 0;
}

Queue* queue_create(void) {
	Queue* q = calloc(1, sizeof(Queue));
	q->elements = malloc(DEFAULT_CAPACITY * sizeof(K));
	q->capacity = DEFAULT_CAPACITY;
	return q;
}

void queue_destroy(Queue* q) {
	free(q->elements);
	free(q);
}

void grow_capacity(Queue* q) {
	int new_capacity = q->capacity <= MAX_PREALLOC ?
		(q->capacity << 1) : (q->capacity + MAX_PREALLOC);

	K* new_elements = malloc(new_capacity * sizeof(K));

	// Ԫ
	for (int i = 0; i < q->size; i++) {
		new_elements[i] = q->elements[(q->front + i) % q->capacity];
	}

	free(q->elements);
	q->elements = new_elements;
	q->front = 0;
	q->rear = q->size;
	q->capacity = new_capacity;
}

void queue_push(Queue* q, K val) {
	if (q->size == q->capacity) {
		grow_capacity(q);
	}
	q->elements[q->rear] = val;
	q->rear = (q->rear + 1) % q->capacity;
	q->size++;
}

K queue_pop(Queue* q) {
	if (queue_empty(q)) {
		printf("Error: queue is empty\n");
		exit(1);
	}

	K val = q->elements[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return val;
}

K queue_peek(Queue* q) {
	if (queue_empty(q)) {
		printf("Error: queue is empty\n");
		exit(1);
	}

	return q->elements[q->front];
}



typedef struct tree_node{
    K key;
    struct tree_node* left;
    struct tree_node* right;
}TreeNode;

typedef struct{
    TreeNode* root;
}BST;

//API
BST* bst_create(void){
    return calloc(1,sizeof(BST));
}

void bst_insert(BST* tree,K key){
    TreeNode* parent = NULL;
    TreeNode* curr = tree->root;
    int cmp;
    while(curr){
        cmp = key - curr->key;
        if(cmp < 0){
            parent = curr;
            curr = curr->left;
        }else if(cmp > 0){
            parent = curr;
            curr = curr->right;
        }else{
            //相等的情况，说明已经存在，直接返回
            return;
        }
    }
    //curr == NULL
    //插入节点
    TreeNode* node = malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    //链接到树中
    if(parent == NULL){
        tree->root = node;
    }else if(cmp < 0){
        parent->left  = node;
    }else if(cmp > 0){
        parent->right = node;
    }else{
        return;
    }
}

void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}
void bst_preorder(BST* tree){
    preorder(tree->root);
    printf("\n");
}

void postorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}
void bst_postorder(BST* tree){
    postorder(tree->root);
    printf("\n");
}

void destroy(TreeNode* root){
    if(root == NULL){
        return;
    }
    destroy(root->left);
    destroy(root->right);
    free(root);
}
void bst_destroy(BST* tree){
    TreeNode* root = tree->root;
    destroy(tree->root);
    free(tree);
    printf("");
}



//API

//层次遍历
void bst_levelorder(BST* tree){
    //1.创建队列
    Queue* q = queue_create();
    //2.将根节点入队列
    queue_push(q, tree->root);
    int count = 1;
    //3.循环遍历
    while(!queue_empty(q)){
        //出队列
        TreeNode* node = queue_pop(q);
        //遍历该节点
        printf("%d ", node->key);
        count--;
        if(count == 0){
            printf("\n");
        }
        //判断该节点是否有左孩子
        if(node->left){
            queue_push(q,node->left);
        }
        if(node->right){
            queue_push(q,node->right);
        }
        if(count == 0){
            count = q->size;
        }
    }// queue_empty(q) == true
    printf("\n");
}


//测试单元
int main(){
   BST* tree = bst_create();
   bst_insert(tree,9);
   bst_insert(tree,5);
   bst_insert(tree,3);
   bst_insert(tree,42);
   bst_insert(tree,13);
   bst_insert(tree,57);
   bst_levelorder(tree);
   return 0;
}
