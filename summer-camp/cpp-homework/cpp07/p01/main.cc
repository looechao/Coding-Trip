// main.cpp
#include<fstream>
#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/RollingFileAppender.hh"

using namespace log4cpp;


int main(int argc, char** argv) {

    //准备好布局
    PatternLayout *ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");
    PatternLayout *ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");
    PatternLayout *ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

	// 准备好目的地
    OstreamAppender * pos = new OstreamAppender("console", &std::cout);
    pos->setLayout(ptn1);


    FileAppender * filePos = new FileAppender("file", "wd.log");
    filePos->setLayout(ptn2);
    
    RollingFileAppender* rfPos = new RollingFileAppender("rollingfile", "rolingfile.log",64,8);
    rfPos->setLayout(ptn3);


    Category & salesDepart = Category::getInstance("looe");

    salesDepart.setPriority(Priority::ERROR);

    salesDepart.addAppender(pos);
    salesDepart.addAppender(filePos);
    salesDepart.addAppender(rfPos);

    int count = 100;
    while(count-- > 0){
        salesDepart.emerg("this is an emerge msg");
        salesDepart.fatal("this is a fatal msg");
        salesDepart.alert("this is an alert msg");
        salesDepart.crit("this is a crit msg");
        salesDepart.error("this is an error msg");
    }

    Category::shutdown();

    return 0;
}
