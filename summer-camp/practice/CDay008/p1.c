#include<stdio.h>

int main(int argc, char* argv[]){
    // argc: argument count,�����в����ĸ���
    // argv: argument vector,�����в������ַ���
    // ��һ�������ǿ�ִ�г����·��
    printf("argc = %d\n", argc);
    //��ӡ���е������в���
    for(int i = 0; i < argc; i++){
        puts(argv[i]);
    }
    return 0;
}