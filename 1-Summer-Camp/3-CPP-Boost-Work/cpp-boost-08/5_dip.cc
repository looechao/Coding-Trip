#include <iostream>
using std::cout;
using std::endl;

class BankWorker{
public:
    virtual ~BankWorker() = default;

    virtual void doBussiness() const = 0;
};

class SaveBusiness : public BankWorker{
public:
    void doBussiness() const override{
        cout << "performing save business" << endl;
    }
};

class PayBusiness : public BankWorker{
public:
    void doBussiness() const override{
        cout << "performing pay business" << endl;
    }
};

class TransferBusiness : public BankWorker{
public:
    void doBussiness() const override{
        cout << "performing transfer business" << endl;
    }
};

void performBussiness(const BankWorker& worker){
    worker.doBussiness();
}

void test0(){
    SaveBusiness saveWorker;
    PayBusiness payWorker;
    TransferBusiness transferWorker;

    performBussiness(saveWorker);
    performBussiness(payWorker);
    performBussiness(transferWorker);

}

int main()
{
    test0();
    return 0;
}

