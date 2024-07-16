#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Student{
public:
    Student()
    : _id(0)
    , _height(0)
    , _name(new char[10]())
    , _score(0)
    {
        strcpy(_name, "looechao");
    }
    Student(int id, double height, const char* name, double score)
        : _id(id)
        , _height(height)
        , _name(new char[strlen(name)+1]())
        , _score(score)
        {
            strcpy(_name, name);
        }
    void print(){
        cout<<"student's info"<<endl;
        cout<<"id:"<<_id<<endl;
        cout<<"height:"<<_height<<endl;
        cout<<"name:"<<_name<<endl;
        cout<<"score:"<<_score<<endl;
    }
private:
    double _height;
    char* _name;
    int _id;
    double _score;
};

int main()
{
    Student s1;
    s1.print();
    Student s2(20203970, 179, "looechao", 100);
    cout<<endl;
    s2.print();
    cout<<endl;
    return 0;
}

