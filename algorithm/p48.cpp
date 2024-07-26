#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    string s1, s2;
    cout<<"输入第一串字符: ";
    getline(cin, s1);
    cout<<"输入第二串字符: ";
    getline(cin, s2);

    if(s1 == s2){
        cout<<"两字符串相等."<<endl;
    }
    else if(s1 > s2){
        cout<<"字符串1较大."<<endl;
    }
    else{
        cout<<"字符串2较大."<<endl;
    }

    //C语言风格
    char s3[80]="^[\0]";
    char s4[80]="^[\0]";
    cout<<"输入第三串字符: ";
    scanf("%s",&s3);
    cout<<"输入第四串字符: ";
    scanf("%s",&s4);
    if(strcmp(s3, s4) == 0){
        cout<<"两字符串相等."<<endl;
    }
    else if(strcmp(s3, s4) > 0){
        cout<<"字符串3较大."<<endl;
    }
    else{
        cout<<"字符串4大."<<endl;
    }

    return 0;
}
