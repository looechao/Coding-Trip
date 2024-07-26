#include <iostream>

int main()
{
    const int& ref = num;
    num = 10;
    ref = 9;
    pritnf("%d", ref);
    return 0;
}

