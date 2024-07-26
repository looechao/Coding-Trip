#include <stdio.h>

long long int fib(int n)
{
    long long a = 0;
    long long b = 1;

    for(int i=2; i <=n; i++){
        long long int t = a+b;
        a = b;
        b = t;
    }
    return b;
}

int main(void)
{
    long long int result = fib(60);
    printf("%lld", result);
    return 0;
}
