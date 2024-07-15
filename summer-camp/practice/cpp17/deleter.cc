#include <iostream>
#include <memory>
#include <string>
using std::unique_ptr;
using std::shared_ptr;
using std::string;
using std::cout;
using std::endl;

void test0(){
    string msg("hello,world\n");
    FILE * fp = fopen("wd.txt", "a+");
    fwrite(msg.c_str(), 1, msg.size(), fp);
    fclose(fp);
}


//专门用于回收文件指针
struct FILEcloser{
    void operator() (FILE* fp){ 
        if(fp){
            fclose(fp);
            cout << "fclose(fp)" << endl;
        }
    }
};

void test1(){
    string msg("hello,world\n");
    unique_ptr<FILE, FILEcloser> up(fopen("wd.txt", "a+"));
    //get函数可以从智能指针中获取到裸指针
    fwrite(msg.c_str(), 1, msg.size(), up.get()); 
    
}


void test2(){
    string msg("hello,world\n");
    FILEcloser fc;
    shared_ptr<FILE> sp(fopen("wd.txt", "a+"), fc);
    fwrite(msg.c_str(), 1, msg.size(), sp.get()); 
}


int main()
{
    test2();
    return 0;
}

