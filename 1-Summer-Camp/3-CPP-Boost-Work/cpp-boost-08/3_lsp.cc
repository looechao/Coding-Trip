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

