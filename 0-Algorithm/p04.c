#include<stdio.h>
#include<string.h>

int main() {
   int number = 1234;
   char str[20];

   for(int i=100;i<=999;i++)
   {
        sprintf(str, "%d", i);
        int a=str[0]-'0';
        int b=str[1]-'0';
        int c=str[2]-'0';
        if(a*a*a+b*b*b+c*c*c==i) printf("%d\n",i);
   }
   return 0;
}
