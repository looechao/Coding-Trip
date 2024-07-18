#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;


template <typename Container>
void display(const Container & con){
    for(auto &ele : con){
        cout << ele.first << " " << ele.second << endl;
    }
    cout << endl;
}


class Replace
{
public:
    void setRules(const string & filename);
    void store(const string & filename);
    void read(const string & filename);
    
private:
    unordered_map<string, string> _rules;    
    unordered_map<string, string> _result;
    vector<string> _file;
};

void Replace::setRules(const string & filename){
    ifstream ifs;
    ifs.open(filename);
    string line;
    while(getline(ifs, line)){
        string key;
        string value;
        auto it = line.begin();
        for(it; it != line.end();){
            if(*it != ' '){
                key += *it;
                ++it;
            }else{
                ++it;
                break;
            }
        }
        for(it; it != line.end(); ++it){
            value += *it;
        }
        _rules[key] = value;
    }
}

void Replace::read(const string & filename){
    ifstream ifs;
    ifs.open(filename);
    string word;
    string line;
    while(getline(ifs, line)){
        auto it = _rules.end();
        istringstream iss(line);
        string final_string;
        while(iss >> word)
        {
            if(_rules.find(word) != it){
                word = _rules[word];
            }
            final_string += word + " ";
        }
        _file.push_back(final_string);
    }
    ifs.close();
}

void Replace::store(const string & filename){
    ofstream ofs(filename);
    for(auto &ele: _file){
        ofs << ele + "\n";
    }
    ofs.close();
}

void test0(){
    Replace rp;
    rp.setRules("map.txt");
    rp.read("file.txt");
    rp.store("result.txt");
}

int main()
{
    test0();
    return 0;
}

