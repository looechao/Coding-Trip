#include <func.h>

int main(int argc, char* argv[])
{
    int a = 0x12345678;
    char* p = (char*) &a;
    printf("p = %x \n", *p);
    return 0;
}

