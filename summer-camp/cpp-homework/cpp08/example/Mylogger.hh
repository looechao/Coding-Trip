#include <iostream>
#include <fstream>
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/RollingFileAppender.hh"
#include <cstdarg>

#define LogWarn(msg, ...) Mylogger::getInstance()->warn(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)
#define LogError(msg, ...) Mylogger::getInstance()->error(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)
#define LogDebug(msg, ...) Mylogger::getInstance()->debug(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)
#define LogInfo(msg, ...) Mylogger::getInstance()->info(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)



using std::cout;
using std::endl;
using log4cpp::Category;
using log4cpp::RollingFileAppender;
using log4cpp::PatternLayout;
using log4cpp::Priority;

class Mylogger{
public:
    static Mylogger* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Mylogger();
        }
        return _pInstance;
    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
        cout << "<<<delete heap" << endl;
    }

    
    void warn(const char* file, const char* func, int line, const char* msg, ...);
    void error(const char* file, const char* func, int line, const char* msg, ...);
    void debug(const char* file, const char* func, int line, const char* msg, ...);
    void info(const char* file, const char* func, int line, const char* msg, ...);
    void fatal(const char* file, const char* func, int line, const char* msg, ...);
    void crit(const char* file, const char* func, int line, const char* msg, ...);
    
private:
    Mylogger();
    ~Mylogger();
    static Mylogger* _pInstance;
    Category& _root;
};


Mylogger::_pInstance = nullptr;
