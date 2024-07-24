## p01
面向对象设计有哪些原则？各自的特点是什么？

单一职责原则：一个类或模块，最好只做一件事，只有一个引起它变化的原因
开放闭合原则：对抽象编程，而不对具体编程，因为抽象相对稳定
里氏替换原则：派生类必须能够替换基类
接口分离原则：使用多个小的专门的接口，而不是使用一个大的总接口
依赖倒置原则：面向接口编程，依赖于抽象
迪米特原则：最少知道原则，最少知识原则，核心思想是减少耦合程度
组合复用原则：在复用时要尽量使用组合、聚合关系，少用继承，就是降低耦合程度

## p02

实现每一种设计原则相关的代码


## 单一职责原则

```cpp
#include <iostream>
using std::cout;
using std::endl;


class Rectangle{
public:
    Rectangle(double w, double h)
    :_width(w)
    ,_height(h)
    {}

    double area() const{
        return _width*_height;
    }

    double getWidth(){
        return _width;
    }

    double getHeight(){
        return _height;
    }
protected:
    int _width;
    int _height;
};

class RectangleGUI : public Rectangle{
public:
    RectangleGUI(double w, double h)
    :Rectangle(w,h){}

    void draw() {
        cout << "rectangle's" << "width:" << getWidth() << endl
            << "rectangle's" << "height:" << getHeight() << endl;
    }
};


void test0(){
    Rectangle rect(10,5);
    cout << "area: " << rect.area() << endl;
    RectangleGUI rectdraw(10,5);
    rectdraw.draw();
}

int main()
{
    test0();
    return 0;
}
```

## 开放闭合原则

```cpp
#include <iostream>
using std::cout;
using std::endl;

class Calculator{
public:
    virtual ~Calculator() = default;
    virtual double getResult(double a, double b) const = 0;
};

class PlusCalculator : public Calculator{
public:
    double getResult(double a, double b) const override{
        return a + b;
    }
};

class MinusCalculator : public Calculator{
public:
    double getResult(double a, double b) const override{
        return a - b;
    }
};

class MultiCalculator : public Calculator{
public:
    double getResult(double a, double b) const override{
        return a * b;
    }
};


class DevideCalculator : public Calculator{
public:
    double getResult(double a, double b) const override{
        return a / b;
    }
};

void test0(){
    PlusCalculator plusCalc;
    MinusCalculator minusCalc;
    MultiCalculator multiCalc;
    DevideCalculator devideCalc;

    cout << "plus: " << plusCalc.getResult(10,5) <<endl;
    cout << "minus: " << minusCalc.getResult(10,5) <<endl;
    cout << "multi: " << multiCalc.getResult(10,5) <<endl;
    cout << "devide: " << devideCalc.getResult(10,5) <<endl;

}

int main()
{
    test0();
    return 0;
}
```

## 里氏替换原则

```cpp
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class User{
public:
    User(string& name, float score)
    :_name(name)
    ,_score(score)
    {}

    virtual void consume(float amount){
        _score -= amount;
        cout << _name << " consumed " << amount << endl;
        cout << "remaining score is " << _score << endl;
    }
protected:
    string _name;
    float _score;
};

class VipUser : public User{
public:
    VipUser(string& name, float score, float discount)
    :User(name, score)
    ,_discount(discount)
    {}

    //重命名consume 满足里氏替换原则
    void vipconsume(float amount){
        float discountedAmount = amount * _discount;
        User::consume(discountedAmount);
        cout << "VIP user: " << _name << " consumed ";
        cout << discountedAmount << " with discount"<< endl << "remaining score is " << _score << endl;
    }

    void updateDiscount(float newDiscount){
        _discount = newDiscount;
    }
private:
    float _discount;
};


void test0(){
    string name1 = "jhon";
    string name2 = "evan";
    User user(name1, 100);
    user.consume(20);

    VipUser vipuser(name2, 100, 0.8);
    vipuser.vipconsume(20);
}

int main()
{
    test0();
    return 0;
}
```

## 接口分离原则

核心思想：使用多个小的专门的接口，而不要使用一个大的总接口。

Bird类包括eat walk chirp

应该让Bird拆分成FlyingBird和Bird

FlyingBird新增fly()

这是Crow可以继承Flyingbird 而 Ostrich可以继承Bird

用CPP模拟这个原则

```cpp
#include <iostream>

// 基类 Bird
class Bird {
public:
    virtual ~Bird() = default;

    virtual void eat() const {
        std::cout << "Bird is eating." << std::endl;
    }

    virtual void walk() const {
        std::cout << "Bird is walking." << std::endl;
    }

    virtual void chirp() const {
        std::cout << "Bird is chirping." << std::endl;
    }
};

// 派生类 FlyingBird
class FlyingBird : public Bird {
public:
    virtual void fly() const {
        std::cout << "FlyingBird is flying." << std::endl;
    }
};

// Crow 继承 FlyingBird
class Crow : public FlyingBird {
public:
    void fly() const override {
        std::cout << "Crow is flying." << std::endl;
    }

    void chirp() const override {
        std::cout << "Crow is cawing." << std::endl;
    }
};

// Ostrich 继承 Bird
class Ostrich : public Bird {
public:
    void walk() const override {
        std::cout << "Ostrich is walking." << std::endl;
    }

    void chirp() const override {
        std::cout << "Ostrich is grunting." << std::endl;
    }
};

int main() {
    Crow crow;
    crow.eat();
    crow.walk();
    crow.chirp();
    crow.fly();

    std::cout << std::endl;

    Ostrich ostrich;
    ostrich.eat();
    ostrich.walk();
    ostrich.chirp();

    return 0;
}
```

## 依赖倒置原则DIP

```cpp
#include <iostream>
#include <string>

// 抽象类 BankWorker
class BankWorker {
public:
    virtual ~BankWorker() = default;

    // 纯虚函数 doBusiness
    virtual void doBusiness() const = 0;
};

// SaveBusiness 类实现 doBusiness
class SaveBusiness : public BankWorker {
public:
    void doBusiness() const override {
        std::cout << "Performing save business." << std::endl;
    }
};

// PayBusiness 类实现 doBusiness
class PayBusiness : public BankWorker {
public:
    void doBusiness() const override {
        std::cout << "Performing pay business." << std::endl;
    }
};

// TransferBusiness 类实现 doBusiness
class TransferBusiness : public BankWorker {
public:
    void doBusiness() const override {
        std::cout << "Performing transfer business." << std::endl;
    }
};

// 高层模块依赖于抽象类 BankWorker
void performBusiness(const BankWorker& worker) {
    worker.doBusiness();
}

int main() {
    SaveBusiness saveWorker;
    PayBusiness payWorker;
    TransferBusiness transferWorker;

    performBusiness(saveWorker);
    performBusiness(payWorker);
    performBusiness(transferWorker);

    return 0;
}
```

## **迪米特原则 (Law of Demeter, LoD) **

又称为最少知道原则 (Principle of Least Knowledge)

- Each unit should have only limited knowledge about other units: only units "closely" related to the current unit.
- 每个单元应该对其他单元有最少的了解：只与当前单元“紧密”相关的单元。

楼盘买房问题，相比于直接看3处房产让买房者找中介买不同的房子

```cpp
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Property{
public:
    Property(const string& address)
    :_address(address){}

    string getAddress() const{
        return _address;
    }
private:
     string _address;
};


class Agent{
public:
    void addProperty(const Property& property){
        properties.push_back(property);
    }

    void showProperties() const{
        for(const auto& property : properties){
            cout << "Property address: " << property.getAddress() << endl;
        }
    }
private:
    vector<Property> properties;
};

class Buyer{
public:
    Buyer(Agent& agent) : agent(agent){}

    void viewProperties() const {
        agent.showProperties();
    }
private:
    Agent& agent;
};

void test0(){
    Agent agent;
    agent.addProperty(Property("wuhan"));
    agent.addProperty(Property("changsha"));
    agent.addProperty(Property("shenzhen"));

    Buyer buyer(agent);
    buyer.viewProperties();
}

int main()
{
    test0();
    return 0;
}
```

## 组合复用原则Composition Over Inheritance Principle)

```cpp
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
```



