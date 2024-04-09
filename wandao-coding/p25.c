#include<stdio.h>
#include<string.h>


int main()
{
    char s1[100]={"My name is Li jilin."};
    char s2[100]={"Mr. Zhang Haoling is very happy."};
    printf("%s \n",s1);
    printf("%s \n",s2);
    // strncpy(destination, source, number)
    strncpy(s1+11,s2+4,13);
    printf("%s \n",s1);
    printf("%s \n",s2);
    return 0;
}
