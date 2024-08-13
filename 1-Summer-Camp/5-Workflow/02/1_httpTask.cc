#include <signal.h>
#include <iostream>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
using std::cout;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum){
    cout << "done! \n";
    waitGroup.done();
}

int main(){
    signal(SIGINT, sighandler);
    WFHttpTask *httpTask = WFTaskFactory::create_http_task(
        "http://www.baidu.com",
        10,10,
        nullptr
    );
    protocol::HttpRequest *req = httpTask->get_req();
    req->add_header_pair("Agent", "Workflow");
    httpTask->start();
    //
    waitGroup.wait();
    cout << "finished! \n";
}