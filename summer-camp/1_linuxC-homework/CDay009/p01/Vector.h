typedef int E;

typedef struct {
    E* elements; //指向堆空间的数组
    int size;
    int capacity;
} Vector;

 //在后面添加元素
 void push_back(Vector* v, E val);

 //在前面添加元素
 void push_front(Vector* v, E val);

// //删除最后一个元素，并返回最后一个元素
   E pop_back(Vector* v);

// //删除第一个元素，并把第一个元素返回
   E pop_front(Vector* v);

Vector* vector_create(void);