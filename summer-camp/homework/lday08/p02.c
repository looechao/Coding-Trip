#include <func.h>

void func(void){
    printf("I am going to die ...");
}

int main(int argc, char* argv[])
{
    int err = atexit(func);
    if(err){
        error(1,0,"atexit");
    }
    
    printf("hello world!");
    exit(123);
}

