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

    
    void warn(const char* file, int line, const char* func, const char* msg, ...);
    void error(const char* file, int line, const char* func, const char* msg, ...);
    void debug(const char* file, int line, const char* func, const char* msg, ...);
    void info(const char* file, int line, const char* func, const char* msg, ...);
    void fatal(const char* file, int line, const char* func, const char* msg, ...);
    void crit(const char* file, int line, const char* func, const char* msg, ...);
    
private:
    Mylogger();
    ~Mylogger();
    static Mylogger* _pInstance;
    Category& _root;
};

Mylogger* Mylogger::_pInstance = nullptr;

Mylogger::Mylogger()
:_root(Category::getRoot().getInstance("MyCategory"))
{
    PatternLayout * pLayout = new PatternLayout();
    pLayout->setConversionPattern("%d [%p] %m%n");
    RollingFileAppender rfPos = new RollingFileAppender("rollingfile", "rollingfile.log", 64, 8);
    rfPos.setLayout(pLayout);
    
    _root.addAppender(rfPos);
    _root.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    Category::shutdown();
}

void Mylogger::warn(const char* file, int line, const char* func, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    
    _root.warn("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::error(const char* file, int line, const char* func, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    
    _root.error("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::debug(const char* file, int line, const char* func, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    
    _root.debug("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::info(const char* file, int line, const char* func, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    
    _root.info("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::fatal(const char* file, int line, const char* func, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    
    _root.fatal("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::crit(const char* file, int line, const char* func, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    
    _root.crit("%s:%d %s - %s", file, line, func, buffer);
}



void test0()
:{
    Mylogger *log = Mylogger::getInstance();

    log->info(__FILE__, __func__, __LINE__, "The log is info message");
    log->error(__FILE__, __func__, __LINE__, "The log is error message");
    log->warn(__FILE__, __func__, __LINE__, "The log is warn message");
    log->debug(__FILE__, __func__, __LINE__, "The log is debug message");
}

void test1() 
{
    printf("hello,world\n");
    LogInfo("The log is info message");
    LogError("The log is error message");
    LogWarn("The log is warn message");
    LogDebug("The log is debug message");
}

int main()
{
    test0();
    test1();
    return 0;
}
