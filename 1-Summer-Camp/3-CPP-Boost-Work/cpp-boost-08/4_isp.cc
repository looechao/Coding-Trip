#include <iostream>
using std::cout;
using std::endl;

class Bird{
public:
    virtual ~Bird() = default;

    virtual void eat() const{
        cout << "Bird is eating" << endl;
    };


    virtual void walk() const{
        cout << "Bird is walking" << endl;
    };

    
    virtual void chirp() const{
        cout << "Bird is chirping" << endl;
    };
};


class FlyingBird : public Bird{
public:
    virtual void fly() const{
        cout << "FlyingBird is flying" << endl;
    }
};

class Crow : public FlyingBird{
public:
    void fly() const override{
        cout << "Crow is flying" << endl;
    }

    void chirp() const override{
        cout << "Crow is cawing" << endl;
    }
};

class Ostrich : public Bird{
public:
    void walk() const override{
        cout << "Ostrich is walking" << endl;
    }
    void chirp() const override{
        cout << "Ostrich is grunting" << endl;
    }
};


void test0(){
    Crow crow;
    crow.eat();
    crow.walk();
    crow.chirp();
    crow.fly();

    cout << endl;

    Ostrich ostrich;
    ostrich.eat();
    ostrich.walk();
    ostrich.chirp();

}

int main()
{
    test0();
    return 0;
}

