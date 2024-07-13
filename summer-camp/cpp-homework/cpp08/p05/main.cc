#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <iostream>
#include <cstdarg>

class Mylogger
{
public:
    static Mylogger* getInstance();

    void warn(const char *file, const char *func, int line, const char *msg, ...);
    void error(const char *file, const char *func, int line, const char *msg, ...);
    void debug(const char *file, const char *func, int line, const char *msg, ...);
    void info(const char *file, const char *func, int line, const char *msg, ...);

private:
    Mylogger();
    ~Mylogger();

    static Mylogger* _pInstance;
    log4cpp::Category& _root;
};

Mylogger* Mylogger::_pInstance = nullptr;

Mylogger::Mylogger()
    : _root(log4cpp::Category::getRoot().getInstance("MyCategory"))
{
    log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
    pLayout->setConversionPattern("%d [%p] %m%n");

    log4cpp::RollingFileAppender* rfPos = new log4cpp::RollingFileAppender("rollingfile", "rollingfile.log", 64, 8);
    rfPos->setLayout(pLayout);

    _root.addAppender(rfPos);
    _root.setPriority(log4cpp::Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    log4cpp::Category::shutdown();
}

Mylogger* Mylogger::getInstance()
{
    if (!_pInstance) {
        _pInstance = new Mylogger();
    }
    return _pInstance;
}

void Mylogger::warn(const char *file, const char *func, int line, const char *msg, ...)
{
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);

    _root.warn("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::error(const char *file, const char *func, int line, const char *msg, ...)
{
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);

    _root.error("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::debug(const char *file, const char *func, int line, const char *msg, ...)
{
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);

    _root.debug("%s:%d %s - %s", file, line, func, buffer);
}

void Mylogger::info(const char *file, const char *func, int line, const char *msg, ...)
{
    char buffer[1024];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);

    _root.info("%s:%d %s - %s", file, line, func, buffer);
}

#define LogWarn(msg, ...) Mylogger::getInstance()->warn(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)
#define LogError(msg, ...) Mylogger::getInstance()->error(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)
#define LogDebug(msg, ...) Mylogger::getInstance()->debug(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)
#define LogInfo(msg, ...) Mylogger::getInstance()->info(__FILE__, __func__, __LINE__, msg, ##__VA_ARGS__)

void test0()
{
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
