#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

class Student{
private:
    string name;
    int score;
public:
    //���캯��
    Student(const string& name, int score) : name(name), score(score) {}
    //��Ԫ����,����ʹ�����ô���
    friend void showscore(Student&);

};

void showscore(Student& st)
{
    cout<<"ѧ��������"<<st.name<<" �ɼ��ȼ�:";
    if (st.score >= 90) {
        cout << "��";
    } else if (st.score >= 80) {
        cout << "��";
    } else if (st.score >= 70) {
        cout << "��";
    } else if (st.score >= 60) {
        cout << "����";
    } else {
        cout << "������";
    }
    cout << endl;
}

int main()
{
    Student s1("����",89);
    Student s2("����",98);
    showscore(s1);
    showscore(s2);
}
