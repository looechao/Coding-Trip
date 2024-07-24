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

