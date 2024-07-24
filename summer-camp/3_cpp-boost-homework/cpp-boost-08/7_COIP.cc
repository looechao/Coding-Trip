#include <iostream>
using std::cout;
using std::endl;

class Vehicle{
public:
    virtual ~Vehicle() = default;

    virtual void run() const{
        cout << "Vehicle is running" << endl;
    }
};


class BYD : public Vehicle{
public:
    void run() const override{
        cout << "BYD is running" << endl;
    }
};

class TESLA : public Vehicle{
public:
    void run() const override{
        cout << "TESLA is running" << endl;
    }
};

class GEELY : public Vehicle{
public:
    void run() const override{
        cout << "GEELY is running" << endl;
    }
};

class Person{
public:
    Person(Vehicle* vehicle)
    :vehicle(vehicle)
    {}

    void drive() const{
        if(vehicle){
            vehicle->run();
        }else{
            cout << "No cat to drive" << endl;
        }
    }
private:
    Vehicle* vehicle;
};


void test0(){
    BYD byd;
    TESLA tsla;
    GEELY gl;
    Person person1(&byd);
    Person person2(&tsla);
    Person person3(&gl);
    person1.drive();
    person2.drive();
    person3.drive();
}

int main()
{
    test0();
    return 0;
}

