#include<stdio.h>

typedef struct student{
    int number;
    char name[25];
    int chinese;
    int math;
    int english;
} Student;

void print_course_info(const Student* pstus[], int n){
    int sum_cn = 0, sum_math = 0, sum_en = 0;
    Student* ptr_max_cn = pstus[0];
    Student* ptr_max_math = pstus[0];
    Student* ptr_max_en = pstus[0];
    for(int i = 0; i < n; i++){
        sum_cn += pstus[i]->chinese;
        sum_math += pstus[i]->math;
        sum_en += pstus[i]->english;
        if(pstus[i]->chinese>ptr_max_cn->chinese){
            ptr_max_cn = pstus[i];
        }
        if(pstus[i]->math>ptr_max_math->math){
            ptr_max_math = pstus[i];
        }
        if(pstus[i]->english>ptr_max_en->english){
            ptr_max_en = pstus[i];
        }
    }
    printf("语文:\n"
           "   平均分数是：%d\n"
           "   最高分的学生信息:\n" 
           "   学号：%d   姓名%s\n"
           "数学:\n"
           "   平均分数是：%d\n"
           "   最高分的学生信息:\n" 
           "   学号：%d   姓名%s\n"
           "英语:\n"
           "   平均分数是：%d\n"
           "   最高分的学生信息:\n" 
           "   学号：%d   姓名%s\n", sum_cn/5, ptr_max_cn->number, ptr_max_cn->name, sum_math/5, ptr_max_math->number, ptr_max_math->name, sum_en/5, ptr_max_en->number, ptr_max_en->name);
}



void sort_students(Student* pstus[], int n){
    for(int i = 0; i < n; i++){
        int total_score_i = pstus[i]->chinese+pstus[i]->math+pstus[i]->english;
        for(int j = i+1; j < n; j++){
            int total_score_j = pstus[j]->chinese+pstus[j]->math+pstus[j]->english;
            if(total_score_j > total_score_i){
                // Here we swap the pointers, not the content itself
                Student* temp = pstus[i];
                pstus[i] = pstus[j];
                pstus[j] = temp;
                
                // update total_score_i
                total_score_i = pstus[i]->chinese+pstus[i]->math+pstus[i]->english;
            }
        }
    }
}

int main(void){
    Student students[5];
    for(int i = 0; i < 5; i++){
        scanf("%d%s %d%d%d", &students[i].number,&students[i].name,&students[i].chinese,&students[i].math,&students[i].english);
    }
    Student* pstus[5] = {students, students+1, students+2, students+3, students+4};
    print_course_info(pstus,5);
    sort_students(pstus,5);
    printf("排序后的成绩单如下：\n");
    for(int i = 0; i < 5; i++){
        printf("%d %s %d %d %d\n", pstus[i]->number,pstus[i]->name,pstus[i]->chinese,pstus[i]->math,pstus[i]->english);
    }
    return 0;
}