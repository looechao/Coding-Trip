#include <func.h>

int main(int argc, char* argv[])
{
    int i = 0x12345678;
    printf("i = %x\n", i);
    char* p = (char*)&i;
    printf("*p = %x\n", *p);
    return 0;
}

