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

