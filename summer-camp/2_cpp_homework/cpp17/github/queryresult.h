#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <string>
#include <set>
#include <vector>
#include <memory>

using std::vector;
using std::set;
using std::string;
using std::shared_ptr;


class QueryResult
{

    public:
        using _lineno = std::vector<std::string>::size_type;

        QueryResult(const string &sought,
                    const shared_ptr<vector<string>>&file,
                     const shared_ptr<set<_lineno>>&lines)
                    :_sought(sought)
                    ,_file(file)
                    ,_lines(lines)
                    {
                    };

        set<_lineno>::size_type size(){return _lines->size();}
//重载输出流函数输出QueryResult对象
        friend std::ostream& operator<<(std::ostream&,const QueryResult&);

    private:
        std::string _sought;
        std::shared_ptr<std::vector<std::string>> _file;
        std::shared_ptr<std::set<_lineno>> _lines;
};

#endif

