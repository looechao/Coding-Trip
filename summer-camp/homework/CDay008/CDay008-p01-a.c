#include<stdio.h>

typedef struct student_s{
    int number;
    char name[25];
    char gender;
    int chinese;
    int math;
    int english;
} Student;

int main(){
    Student s1 = {2020,"zhaolu",'f',100,100,100};
    return 0;
}