#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>

#define DEFAULT_CAPACITY    4
#define LOAD_FACTOR      0.5

typedef char* K;
typedef char* V;

typedef struct node {
    K key;
    V val;
    struct node* next;
}Node;

typedef struct{
    Node** table;
    int size;   // 指KV对的个数
    int capacity;
    uint32_t hashseed;
}HashMap;

//外部API
// key: 关键字的地址
// len: 关键字的字节长度
// seed: 哈希种子，避免攻击
uint32_t hash(const void* key, int len, uint32_t seed) {
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    uint32_t h = seed ^ len;
    const unsigned char* data = (const unsigned char*)key;

    while (len >= 4) {
        uint32_t k = *(uint32_t*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len)
    {
    case 3: h ^= data[2] << 16;
    case 2: h ^= data[1] << 8;
    case 1: h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

//API
HashMap* hashmap_create(void){
    HashMap* map = malloc(sizeof(HashMap));
    if(!map){
        printf("Error! Failed to malloc for hashmap!");
        exit(1);
    }
    map->table = calloc(DEFAULT_CAPACITY, sizeof(Node*));
    map->size = 0;
    map->capacity = DEFAULT_CAPACITY;
    map->hashseed = time(NULL);

    return map;
}

//扩容
void grow_capacity(HashMap* map){
    int new_capacity = map->capacity * 2;
    Node** new_table = calloc(new_capacity, sizeof(Node*));
    if(!new_table){
        printf("Error! Failed to malloc for new_table!");
        exit(1);
    }
    map->hashseed = time(NULL);
    for(int i = 0; i < map->capacity; i++){
        Node* curr = map->table[i];
        while(curr){
            K key = curr->key;
            V val = curr->val;
            int idx = hash(key,strlen(key),map->hashseed)%new_capacity;
            Node* newnode = malloc(sizeof(Node));
            newnode->key = key;
            newnode->val = val;
            newnode->next = new_table[idx];
            new_table[idx] = newnode;
            curr = curr->next;
        }
    }
    map->table = new_table;
    map->capacity = new_capacity;
}



//如果key不存在，添加key-val,并返回null
V hashmap_put(HashMap* map, K key, V val){
    if(map->size+1 > map->capacity*LOAD_FACTOR){
        grow_capacity(map);
    }
    int idx = hash(key,strlen(key),map->hashseed)%map->capacity;
    Node* curr = map->table[idx];
    while(curr){
        if(strcmp(curr->key,key)==0){
            //key存在，返回原来的值
            V oldval = curr->val;
            curr->val = val;
            return oldval;
        }
        curr = curr->next;
    }
    //key不存在，添加key-val,返回NULL，用头插法
    Node* newnode = malloc(sizeof(Node));

    newnode->key = key;
    newnode->val = val;
    newnode->next = map->table[idx];
    map->table[idx] = newnode;
    map->size++;
    return NULL;
}

V hashmap_get(HashMap* map, K key){
    int idx = hash(key,strlen(key),map->hashseed)%map->capacity;
    Node* curr = map->table[idx];
    while(curr){
        if(strcmp(curr->key,key) == 0){
            return curr->val;
        }
        curr = curr->next;
    }
    return NULL;
}

//删除键值对，如果key不存在，什么都不做
void hashmap_delete(HashMap* map, K key){
    int idx = hash(key,strlen(key),map->hashseed)%map->capacity;
    Node* prev = NULL;
    Node* curr = map->table[idx];
    while(curr){
        if(strcmp(curr->key,key) == 0){
            //todo 删除curr节点
            if(prev == NULL){
                map->table[idx] = curr->next;
            }else{
                prev->next = curr->next;
            }
            free(curr);
            map->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

//销毁hash表,自底向上销毁
void hashmap_destroy(HashMap* map){
    for(int i = 0; i < map->capacity; i++){
        Node* curr = map->table[i];
        while(curr){
            Node* next = curr->next;
            free(curr);
            curr = next;
        }
        //释放动态数组
        free(map->table);
    }
    free(map);
}



//测试单元

int main(){
    HashMap* hm = hashmap_create();
    printf("the capacity is %d, the size is %d\n", hm->capacity,hm->size);
    hashmap_put(hm,"wbq","mr");
    printf("the capacity is %d, the size is %d\n", hm->capacity,hm->size);    
    hashmap_put(hm,"lqd","zjt");
    printf("the capacity is %d, the size is %d\n", hm->capacity,hm->size);
    hashmap_put(hm,"zhy","360");    
    printf("the capacity is %d, the size is %d\n", hm->capacity,hm->size);
    hashmap_put(hm,"xsd","238");    
    printf("the capacity is %d, the size is %d\n", hm->capacity,hm->size);
    return 0;
}