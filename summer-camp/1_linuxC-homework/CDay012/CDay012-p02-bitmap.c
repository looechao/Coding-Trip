#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

#define BITS_PER_WORD 32
#define BITMAP_SHIFT 5
#define BITMAP_MASK 0X1F
#define MAX 123

#define BITMAP_SIZE(bits) ((bits + BITS_PER_WORD - 1) >> BITMAP_SHIFT)

typedef uint32_t Word;

typedef struct{
    uint32_t* array;
    size_t bits;
}BitMap;

//API
BitMap* bitmap_create(size_t bits){
    BitMap* bm = malloc((sizeof(BitMap)));
    if(!bm){
        printf("Error:failed to allocate for bitmap");
        exit(1);
    }
    bm->array = calloc(BITMAP_SIZE(bits),BITS_PER_WORD >> 3);
    if(!bm->array){
        printf("Error:failed to allocate for bm->array");
        exit(1);
    }
    bm->bits = bits;
    return bm;
}

//扩充位图，能够存下Bits�?
void grow_capacity(BitMap* bm, size_t bits){
    //位图：内存紧凑的数据结构，应尽可能少的减少扩充空�?
    //扩容策略，需要多大，就申请多大的内存空间,可以考虑使用relloc函数
    uint32_t* new_array = realloc(bm->array, BITMAP_SIZE(bits)*(BITS_PER_WORD >> 3));
    if(!new_array){
        printf("Error:failed to allocate in new_array");
        exit(1);
    }
    bm->array = new_array;
    //将扩充的部分置为0
    int bytes = (BITMAP_SIZE(bits) - BITMAP_SIZE(bm->bits)) * (BITS_PER_WORD>>3);
    memset(bm->array + BITMAP_SIZE(bm->bits),0,bytes);
}

void bitmap_set(BitMap* bm, size_t n){
    //考虑容量不够的情况，需要扩�?
    if(n+1 > bm->bits){
        if(BITMAP_SIZE(n+1)>BITMAP_SIZE(bm->bits)){
            grow_capacity(bm,bm->bits);
        }
        bm->bits = n+1;
    }

    //如果容量足够，直接设置第n�?
    size_t word = n>>BITMAP_SHIFT;
    size_t offset = n & 0x1f;
    bm->array[word] |= (0x1 << offset);
}


void bitmap_unset(BitMap* bm, size_t n) {
	if (n >= bm->bits) {
		return;
	}
	// 找到第n�? (word, offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	bm->array[word] &= ~(0x1 << offset);
}



bool bitmap_isset(BitMap* bm, size_t n){
    //找到第n�?
    if(n >= bm->bits){
        return false;
    }
    //找到第n�?
    size_t word = n >> BITMAP_SHIFT;
    size_t offset = n & BITMAP_MASK;
    return bm->array[word] & (0x1 << offset); /*000001000*/; 
}

void bitmap_clear(BitMap* bm) {
	size_t bytes = BITMAP_SIZE(bm->bits) * sizeof(Word);
	memset(bm->array, 0, bytes);
}

void bitmap_destroy(BitMap* bm){
    free(bm->array);
    free(bm);
}

//测试单元
int main(){
    int max = MAX;
    char str[max];
    printf("��������Ҫ�������ַ���:\n");
    scanf("%s",str);
    remove_duplicate_and_sort(str);
}

void remove_duplicate_and_sort(char* str){
    BitMap* bm = bitmap_create(MAX);
    while(*str){
        int i = *str;
        bitmap_set(bm,i);
        str++;
    }
    for(int i=0; i<=MAX; i++){
        while(bitmap_isset(bm,i)){
            printf("%c",i);
            break;
        }
    }
    printf("\n");
}