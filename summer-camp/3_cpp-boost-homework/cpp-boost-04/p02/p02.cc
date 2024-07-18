#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
using std::to_string;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::unordered_map;


class Dictionary
{
public:
    void read(const string & filename);
    void store(const string & filename);
private:
    unordered_map<string, int> _dict;    
};


void Dictionary::read(const string & filename){
    ifstream ifs(filename);
    string word;
    while(ifs >> word){
        auto it = word.begin();
        while(it != word.end()){
            if(!isalpha(*it)){
                it = word.erase(it);
            }else{
                ++it;
            }
        }
        ++_dict[word];
    }
    ifs.close();
}

void Dictionary::store(const string & filename){
    ofstream ofs(filename);
    for(auto &ele : _dict){
        string line = ele.first + " " + to_string(ele.second) + "\n";
        ofs << line;
    }
    ofs.close();
}

void test0(){
    Dictionary* dict = new Dictionary();
    dict->read("thb");
    dict->store("result");
    delete dict;
}

int main()
{
    test0();
    return 0;
}

