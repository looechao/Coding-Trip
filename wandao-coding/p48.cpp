#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    string s1, s2;
    cout<<"�����һ���ַ�: ";
    getline(cin, s1);
    cout<<"����ڶ����ַ�: ";
    getline(cin, s2);

    if(s1 == s2){
        cout<<"���ַ������."<<endl;
    }
    else if(s1 > s2){
        cout<<"�ַ���1�ϴ�."<<endl;
    }
    else{
        cout<<"�ַ���2�ϴ�."<<endl;
    }

    //C���Է��
    char s3[80]="^[\0]";
    char s4[80]="^[\0]";
    cout<<"����������ַ�: ";
    scanf("%s",&s3);
    cout<<"������Ĵ��ַ�: ";
    scanf("%s",&s4);
    if(strcmp(s3, s4) == 0){
        cout<<"���ַ������."<<endl;
    }
    else if(strcmp(s3, s4) > 0){
        cout<<"�ַ���3�ϴ�."<<endl;
    }
    else{
        cout<<"�ַ���4��."<<endl;
    }

    return 0;
}
