#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string,int> mymap;
    mymap = {{"Alice",25}};
    cout<<mymap["Alice"];
    return 0;
}
