#include <stdio.h>

int main()
{
    int x=10,y=4,z=1;
    y >>= x & 0x2 && z;
    printf("%d %d %d \n", x,y,z);
    return 0;
}