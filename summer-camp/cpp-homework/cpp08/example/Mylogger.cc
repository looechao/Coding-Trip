#include <iostream>
#include "Mylogger.hh"
using std::cout;
using std::endl;

Mylogger::Mylogger()
:_root(Category::getRoot().getInstance("MyCategory"))
{
    PatternLayout * pLayout = new PatternLayout();
    pLayout->setConversionPattern("%d [%p] %m%n");
    RollingFileAppender* rfPos = new RollingFileAppender("rollingfile", "rollingfile.log", 64, 8);

    rfPos->setLayout(pLayout);

    _root.addAppender(rfPos);
    _root.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    Category::shutdown();
}

void Mylogger::warn(const char* file, const char* func, int line, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);

    _root.warn("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::error(const char* file, const char* func, int line, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);

    _root.error("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::debug(const char* file, const char* func, int line, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);

    _root.debug("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::info(const char* file, const char* func, int line, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);

    _root.info("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::fatal(const char* file, const char* func, int line, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);

    _root.fatal("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::crit(const char* file, const char* func, int line, const char* msg, ...){
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);

    _root.crit("%s:%d %s - %s", file, line, func, buffer);
}


