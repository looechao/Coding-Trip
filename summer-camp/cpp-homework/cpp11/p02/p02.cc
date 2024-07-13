#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class TextQuery
{
public:
    void readFile(const string& filename);
    void query(const string& word);
    void dealLine(string & Line);

private:
    vector<string> _lines;
    map<string, int> _dict;
    map<string, set<int>> _wordNumbers;
};

void TextQuery::readFile(const string& filename)
{
    ifstream ifs(filename);
    if (!ifs)
    {
        cerr << "Failed to open file." << endl;
        return;
    }

    string line;
    int lineNum = 1;
    while (getline(ifs, line))
    {
        _lines.push_back(line);
        dealLine(line);

        
        istringstream iss;
        string word;
        while(iss >> word){
            ++_dict[word];
            _wordNumbers[word].insert(lineNum);
        }
        lineNum++;
    }
    ifs.close();
}

void TextQuery::query(const string& word)
{
    cout << "-----------------------" << endl;
    int count = _dict[word];
    cout << word << "occurs " << count << (count > 1 ? " times." : " time") << endl;
    auto lines = _wordNumbers[word];
    for(auto & num : lines){
        cout << "(line " << num 
            << ")" << _lines[num - 1] << endl;
    }
    
}

void TextQuery::dealLine(string& Line){
    for(auto & ch : Line){
        if(!isalpha(ch)){
            ch = ' ';
        }else if(isupper(ch)){
            ch = tolower(ch);
        }
    }
}

int main(int argc, char* argv[])
{
    string query_word;
    string file_name;
    cout << "please input filename:" << endl;
    cin >> file_name;
    cout << "please input query word:" << endl;
    cin >> query_word;
    string queryWord(query_word);

    TextQuery tq;
    tq.readFile(file_name);
    tq.query(queryWord);

    return 0;
}
