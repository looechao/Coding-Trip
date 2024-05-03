typedef int E;

typedef struct {
    E* elements; //ָ��ѿռ������
    int size;
    int capacity;
} Vector;

 //�ں������Ԫ��
 void push_back(Vector* v, E val);

 //��ǰ�����Ԫ��
 void push_front(Vector* v, E val);

// //ɾ�����һ��Ԫ�أ����������һ��Ԫ��
   E pop_back(Vector* v);

// //ɾ����һ��Ԫ�أ����ѵ�һ��Ԫ�ط���
   E pop_front(Vector* v);

Vector* vector_create(void);