## p01
无序关联式容器有哪些？各自具有哪些特点？

- unordered_set:
    1. 存放的是key类型，key值是唯一的，不能重复
    2. key值是没有顺序的
    3. 底层使用的是hash
- unordered_multiset:
    与unordered_set性质基本相似，区别是key值可以重复
- unordered_map:
    1. 存放的是key-value类型，key值是唯一的，不能重复
    2. key值是没有顺序的
    3. 底层使用的是hash
- unordered_multimap:
    与unordered_map性质基本相似，区别是key值可以重复
    
## p02
使用unordered_map重写词频统计作业。再比较一下使用map和vector时所花费的时间，体会这几种容器的区别

```cpp
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
```


## p03 
使用unordered_map/map实现单词转换程序。给定一个string，将它转换为另一个string。程序的输入是两个文件，第一个文件保存的是一些规则，用来转换第二个文件中的文本。每条规则由两部分组成：一个可能出现在输入文件中的单词和一个用来替换它的短语。表达的含义是，每当第一个单词出现在输入中时，我们就将它替换为对应的短语，第二个输入文件包含要转换的文本。（C++ primer 11.3.6）

提示：

规则文件：map.txt文件，其实就是第一个单词，被后面的一串所替换。

待转换文本：file.txt文件，该文件中的单词如果出现在map.txt文件的第一个单词的话，就用map.txt的后面一串替代。

结果：最后结果其实就是，将file.txt文件中的并且出现在map.txt中第一个单词转换为map.txt后面的一串。例如：where r u的输出结果就是where are you. r替换为are，u替换为you

```cpp
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

```
