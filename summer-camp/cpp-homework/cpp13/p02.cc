#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class Person{
public:
    Person(const char* name, int age)
    :_name(new char[strlen(name)+1])
     ,_age(age)
    {
        strcpy(_name, name);
    }

    Person(const Person& rhs){
        _name = new char[strlen(rhs._name) + 1];
        strcpy(_name, rhs._name);
        _age = rhs._age;
    }

    ~Person(){
        delete[] _name;
    }

    Person& operator=(const Person& rhs){
        //1.考虑自赋值问题
        // 自赋值，返回自己本身
        if(this != &rhs){
            if(_name){
                delete [] _name;
            }
            // 深拷贝
            _name = new char[strlen(rhs._name) + 1]();
            strcpy(_name, rhs._name);
        }
        return *this;
    }

    void display() const{
        cout << "姓名:" << _name << endl;
        cout << "年龄:" << _age << endl;
    }
private:
    char* _name;
    int _age;
};


class Employee : public Person{
public:
    Employee(const char* name, int age, const char* department, double salary)
    :Person(name, age)
    ,_department(new char[strlen(department)+1])
    ,_salary(salary)
    {
        strcpy(_department, department);
    }

    Employee(const Employee& rhs)
    :Person(rhs)
    ,_department(new char[strlen(rhs._department) + 1])
    ,_salary(rhs._salary)
    {
        strcpy(_department, rhs._department);
    }

    ~Employee() {
        if(!_department){
            delete[] _department;
        }
    }

    Employee& operator= (const Employee& rhs){
        //考虑自赋值，释放左值，深拷贝
        if(this != &rhs){
            Person::operator=(rhs);
            delete[] _department;
            //深拷贝
            _department = new char[strlen(rhs._department)+1];
            strcpy(_department, rhs._department);
            _salary = rhs._salary;
        }
        return *this;
    }

    void display() const{
        Person::display();
        cout << "部门:" << _department << endl;
        cout << "工资:" << _salary << endl;
    }

    static double calculateAverageSalary(Employee* empArry, int size){
        if(size == 0){
            return 0.0;
        }

        double totalSalary = 0.0;
        for(int i = 0; i < size; ++i){
            totalSalary = empArry[i]._salary;
        }

        return totalSalary / size;
    }

protected:
    char* _department;
    double _salary;
};


int main(){
    Employee emp1("John", 30, "Sales", 5000.00);
    Employee emp2("Niko", 23, "Marketing", 5500.00);
    Employee emp3("Rain", 22, "Advertising", 6000.00);
    Employee emp4("Twistzz", 21, "Service", 7000.00);
    
    emp1.display();
    cout << endl;

    emp2.display();
    cout << endl;


    emp3.display();
    cout << endl;


    emp4.display();
    cout << endl;
    
    int size = 4;
    Employee emp[4] = {emp1, emp2, emp3, emp4};
    

    cout << "平均薪资:" <<  Employee::calculateAverageSalary(emp, size)
        << endl;
    
    return 0;
}



