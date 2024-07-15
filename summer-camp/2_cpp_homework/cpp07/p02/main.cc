#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>
#include <ctype.h>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::isalpha;

struct Record
{
    string _word;
    int _frequency;
};

class Dictionary
{
public:
    void read(const string &filename);
    void store(const string &filename);
private:
    vector<Record> _dict;
};

void Dictionary::read(const string &filename){
    ifstream ifs(filename);    
    string word;
    bool found;
    while(ifs >> word){
        found = false;
        word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c) { return !std::isalpha(c); }), word.end());
        for(auto &ele : _dict){
            if(ele._word == word){
                ele._frequency++;
                found = true;
                break;
            }
        }
        if(!found){
            _dict.push_back({word, 1});
        }
    }
    ifs.close();
}

void Dictionary::store(const string &filename){
    ofstream ofs(filename);
    for(auto &ele : _dict){
        string line = ele._word + " " + to_string(ele._frequency) + "\n";
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

