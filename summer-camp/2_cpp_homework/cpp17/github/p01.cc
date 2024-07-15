#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


class Dictionary
{
public:
    void read(const string &filename);
    void store(const string &filename);
private:
    map<string, int> _dict;
};

void Dictionary::read(const string &filename){
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

void Dictionary::store(const string &filename){
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

