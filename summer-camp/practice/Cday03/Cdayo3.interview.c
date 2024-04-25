#include <stdio.h>
#include <stdbool.h>

bool isOdd(int n)
{
    return n % 2 == 1;
}

int main()
{
    printf("isOdd(-1)=%s\n", isOdd(-1) ? "true" : "false");
    return 0;
}