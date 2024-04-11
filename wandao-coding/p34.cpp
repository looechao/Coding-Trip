#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

class Student{
private:
    string name;
    int score;
public:
    //构造函数
    Student(const string& name, int score) : name(name), score(score) {}
    //友元函数,可以使用引用传递
    friend void showscore(Student&);

};

void showscore(Student& st)
{
    cout<<"学生姓名："<<st.name<<" 成绩等级:";
    if (st.score >= 90) {
        cout << "优";
    } else if (st.score >= 80) {
        cout << "良";
    } else if (st.score >= 70) {
        cout << "中";
    } else if (st.score >= 60) {
        cout << "及格";
    } else {
        cout << "不及格";
    }
    cout << endl;
}

int main()
{
    Student s1("张三",89);
    Student s2("李四",98);
    showscore(s1);
    showscore(s2);
}
